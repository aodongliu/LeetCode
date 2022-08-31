class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int curMin = 1;
        int curMax = 1;
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            /*
            if(nums[i] == 0)
            {
                curMin = 1;
                curMax = 1;
                continue;
            }
            */
            
            int temp1 = nums[i]*curMax;
            int temp2 = nums[i]*curMin;
            curMax = max( max(nums[i], temp1), temp2);
            curMin = min( min(nums[i], temp1), temp2);
            res = max(res, curMax);
            
        }
        
        return res;
    }
};
