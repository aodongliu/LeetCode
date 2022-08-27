class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int j = 0;
        int k = 0;
        int n = nums.size();
        
        std::stack<int> inc_stack;
        std::stack<int> dec_stack;
        
        //increasing stack to substract all the minumums in all possible subarrays
        for(int i = 0; i <= n ; i++)
        {
            while(!inc_stack.empty() && nums[inc_stack.top()] > (i == n ? -2e9 : nums[i]) )
            {
                j = inc_stack.top();
                inc_stack.pop();
                k = inc_stack.empty() ? -1 : inc_stack.top();
                sum -= (long long) nums[j] * (i-j) * (j-k);
            }
            inc_stack.push(i);
        }
        
        //decreasing stack to add all the maximums in all possible subarrays
        for(int i = 0; i <= n; i++)
        {
            while(!dec_stack.empty() && nums[dec_stack.top()] < (i == n ? 2e9 : nums[i]) )
            {
                j = dec_stack.top();
                dec_stack.pop();
                k = dec_stack.empty() ? -1 : dec_stack.top();
                sum += (long long) nums[j] * (i-j) * (j-k);
            }
            dec_stack.push(i);
        }
        
        return sum;
    }
};
