using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int totalStrength(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),0);
        
        vector<LL> presum(n+2,0);
        for(int i = 1; i <=n ; i++) presum[i] = (presum[i-1] + nums[i]) % M;

        
        vector<LL> presum2(n+2,0);
        for(int i = 1; i <=n ; i++) presum2[i] = (presum2[i-1] + (LL)nums[i]*i) % M;

        
        stack<int> stack;
        vector<int> nextSmaller(n+2, n+1);
        vector<int> prevSmaller(n+2, 0);
        for(int i = 1; i <=n ; i++)
        {
            while(!stack.empty() && nums[stack.top()] > nums[i])
            {
                nextSmaller[stack.top()] = i;
                stack.pop();
            }
            if(!stack.empty()) prevSmaller[i] = stack.top();
            stack.push(i);
        }
        
        LL result = 0;
        for(int i = 1; i <= n; i++)
        {
            LL a = prevSmaller[i], b = nextSmaller[i];
            LL x = i-a, y = b-i;
            LL left = ( (presum2[i-1] - presum2[a]) - (presum[i-1] -presum[a])*a % M + M ) % M;
            left = left * y % M;
            LL right =( (presum[b-1] - presum[i])*b % M - (presum2[b-1] -presum2[i]) + M ) % M;
            right = right * x % M;
            LL mid = (LL)nums[i] * x * y % M; 
            result = ( result + (left + mid + right) * nums[i] ) % M; 
            
        }
        
        return result;
        
        
    }
};
