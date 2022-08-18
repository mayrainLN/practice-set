class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0,len = nums.length;
        for(int i: nums){
            sum+=i;
        }
        // 数组和为奇数，不可能。
        if(sum%2!=0){
            return false;
        }

        int target = sum/2;
        // dp[i][j]  0~i数中，选取某些数，他们的和能达到j；
        boolean[][] dp = new boolean[nums.length][target+1];
        // 返回值：dp[len-1][target]  数组中选中某些数，和为target

    //    for(int i=0;i<len;i++){
    //         for(int j = 0;j<=target;j++){
    //             dp[i][j]=false;
    //         }
    //     }
	 // 不用初始化

        // 初始化  选中第一个数
        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }

        // dp[i][j] = 没选中i项 dp[i-1][j] || 选中i项 dp[i-1][ j-nums[i] ];
        for(int i=1;i<len;i++){
            //选中第一个数的情况已经初始化了，只有那一种情况才能为真
            for(int j = 0;j<=target;j++){
                if(j>=nums[i]){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[len-1][target];
    }
}