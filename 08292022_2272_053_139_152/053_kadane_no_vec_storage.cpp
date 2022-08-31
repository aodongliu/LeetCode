class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int temp = res;
        for (int i = 1; i < n; i++)
        {
            temp = max(nums[i], temp+nums[i]);
            res = max(res, temp);
        }
        
        return res;
        
    }
};
