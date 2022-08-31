class Solution {
public:
    int largestVariance(string s) 
    {
        vector<int> count(26,0);
        for(auto x:s) count[x-'a']++;
        
        int res = 0;
        int n = s.size();
        for (int i = 0; i < 25; i++)
        {
            if(count[i] == 0 ) continue;
            for (int j = i+1; j < 26; j++)
            {
                if(count[j] == 0 ) continue;

                res = max(res, max(Kadane(i,j,s), Kadane(j,i,s)));
            }
        }
        
        return res;
    }
    
    
    int Kadane(int x, int y, string &s)
    {
        int d = 0, n = s.size();
        int ans = 0, ycnt = 0;
        for(int i = 0; i < n; i++)
        {
            if((s[i]-'a') == x)
            {
                d++;
            }
            else if((s[i]-'a') == y)
            {
                d--;
                ycnt = 1;
            }
            if(ycnt != 0)
            {
                ans = max(ans, d);
            }
            else
            {
                ans = max(ans, d-1);
            }
            if(d < 0)
            {
                ycnt = 0;
                d = 0;
            }
        }
        return ans;
    }
};
