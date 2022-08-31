using LL = long long;
class Solution {
public:
    long long appealSum(string s) {
	      //again, set initial value to be -1 to account for the edge case
        vector<int> last(26,-1);
        int n = s.length();
        LL res = 0;
        for( int i = 0; i < n; ++i )
        {
						//here I use the define that in the case that there are more multiple same letters in the substring the left character is the unique one 
						//then the problem is much simpler than 2262. We just need to keep track of the last occurence of the same letter (default is -1 to account for edge case)
						//the left boundary can be anywhere between the current occurence index and the last occurence index. We don't need to care about the right boundary at all since we defined only the left character (if there are duplicate letters) to be unique. The right boundary is always the end of the string  
            res += (i-last[s[i]-'a']) * (n-i);
            last[s[i]-'a'] = i;
        }
        return res;
    }
};

