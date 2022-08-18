class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        // left + right = sum
        // left - right = target
        // left = (sum+target)/2
        // 选出若干数 和为left
        // 背包容量为left 
        int sum = 0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
        }
        if((sum+target)%2==1||sum<target||sum+target<0){
            // 无解
            return 0;
        } 
        // 加数的和为left
        int bagSize = (sum+target)/2;
        // nums[j] ： 塞满容量为j的背包有nums[j]种方法
        int[] dp = new int[bagSize+1]; 
        // dp[j] = 不放i dp[j] + 放i dp[j-nums[i]]
        // 初始化: 塞满容量为0的背包，有1种方法，即什么都不放
        dp[0]=1;
        for(int i=0;i<nums.length;i++){
            // 数组中的数0~i
            for(int j=bagSize;j>=nums[i];j--){
                dp[j] +=dp[j-nums[i]];
            }
        }
       return dp[bagSize];
    }
}