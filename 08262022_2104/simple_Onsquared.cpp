class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        int curMax = 0;
        int curMin = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curMax = nums[i];
            curMin = curMax;
            for (int j = i; j < nums.size(); j++)
            {
                curMax = max(curMax, nums[j]);
                curMin = min(curMin, nums[j]);
                sum += curMax - curMin;
            }
        }
        return sum;
    }
};
