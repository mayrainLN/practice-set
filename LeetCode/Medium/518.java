class Solution {
    public int change(int amount, int[] coins) {
        // 求组合种类，完全背包
        // dp[i] 总额为i的组合，共有dp[i]种
        int[] dp = new int[amount+1];
        // 递推公式：dp[j] = dp[j]+dp[j-coins[i]]
        // 初始化：dp[j] = 0;
        dp[0] = 1;
        for(int i=0;i<coins.length;i++){
            // 完全背包
            // dp[j]（考虑coins[i]的组合总和）= 所有dp[j-coins[i]]相加
            for(int j=coins[i];j<=amount;j++){
                dp[j] = dp[j]+dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
}