// O(NlogN) solution
// Intuition:
// We scan through all elements in the array, and build a "sorted", increasing array while scanning through the elements.
// If the next element is larger than the previous element, then it belongs in the increasing sequence, we append it towards the end.
// If the next element is smaller than the previous element, but larger than some earlier element, then we need to use it to replace the element in our increasing array that is just larger than it (this is where LogN comes in). This is justified because we can not re-order elements in subarrays. We can ignore elements. Replacing other element's value is totally fine because the count for LIS will not change. Moreover, since we replace the element that's just larger than it, we have more chances to build a even longer LIS

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS;
        LIS.push_back(INT_MIN);
        
        for(int num : nums){
            // if next element is larger than current largest (which is .back() because LIS is increasing), then append it to the end
            if( num > LIS.back()) {
                LIS.push_back(num);
            } else{
            // Otherwise, find the correct element (the one that is just larger than num), and use num to replace it    
            // Since we need greater or equal, we should use lowerbound function
                LIS[lower_bound(LIS.begin(), LIS.end(), num) - LIS.begin()] = num;
            }
        }
        
        return LIS.size()-1;
    }
};
