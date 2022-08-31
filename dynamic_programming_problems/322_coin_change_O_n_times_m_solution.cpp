class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // get the coin change count from 0 all the way up to amount. This is dynamic programming to avoid repeated calculatios
        vector<int> dp(amount+1, amount+1);
        
        // base case
        dp[0] = 0;
        
        for(int i = 1; i <= amount; ++i)
        {
            // loop over all the coin values to find the miminum count for i
            for (int j : coins)
            {
                if (i >= j) dp[i] = min(dp[i], 1+dp[i-j]);
            }
        }
        
        // if default value, that means we did not get a viable solution, return -1
        return dp[amount] != amount+1 ? dp[amount] : -1;
        
    }
};
