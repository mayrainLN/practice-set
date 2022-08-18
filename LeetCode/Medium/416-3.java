class Solution {
    public boolean canPartition(int[] nums) {
  
        // dp[i][j] 前i个数，选出一部分放入j容量的背包，(最大)价值是dp[i][j]，如果符合条件，最大价值dp[i][j]一定等于j
        // dp[i][j] = max(dp[i-1][j], dp[i-1][ j-weight[i] ]+ value[i] );

        int target=0,sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        target= sum/2;
        int[] dp = new int[target+1];
        // 初始化：
        // dp[][0]=0; 默认值就是0，无需再初始化
        // 需要将i=0的情况初始化 即只放0号物品
        for(int j=nums[0];j<=target;j++){
            // 容量放得下0号物品
            dp[j]=nums[0];
        }
        for(int i=1;i<nums.length;i++){
            for(int j=target;j>=0;j--){
                if(j>=nums[i]){
                    dp[j] = Math.max(dp[j], dp[ j-nums[i] ]+ nums[i] );
                }
            }
        }

        if(dp[target]==target){
            return true;
        }   
        return false;
    }
}