class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // This is dynamic programming. Time complexity O(N^2). Not the best solution
        
        int n = nums.size();
        // initial value set to 1. LIS starting from each index should be set to 1 by default
        vector<int> dp(n, 1);
        
        // use nested loop and starting backwards. Cache previous results in dp
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n ; j++){
                // if i < j, then the larger sequence should either be dp[i] itself or dp[j]+1 (to append i in the beginning of the sequence)
                if(nums[i] < nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
