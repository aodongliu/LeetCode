class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        for( int i = n-1; i >= 0; i--)
        {
            for(string x: wordDict){
                int len_x = x.length(); 
                int end = i + len_x;
                if( end > n) continue;
                if( s.substr(i,len_x) == x)  dp[i] = dp[end];
                if(dp[i])    break;
            }    
        }
        
        return dp[0];
        
    }
};
