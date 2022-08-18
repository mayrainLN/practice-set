class Solution {
    public int combinationSum4(int[] nums, int target) {
        // 求排列数，完全背包
        // dp[i] 总额为i的组合，共有dp[i]种
        int[] dp = new int[target+1];
        // 递推公式：dp[j] = dp[j]+dp[j-coins[i]]
        // 初始化：dp[j] = 0;
        dp[0] = 1;
        for(int j=0;j<=target;j++){
            // 完全背包
            // dp[j]（考虑coins[i]的组合总和）= 所有dp[j-coins[i]]相加
            for(int i=0;i<nums.length;i++){
                if(j>=nums[i]){
                    dp[j] = dp[j]+dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
}