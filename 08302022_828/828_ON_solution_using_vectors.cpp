class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>>pos(26,{-1}); 

        for (int i=0; i<n; i++)  pos[s[i]-'A'].emplace_back(i);
        for (int i=0; i<n; i++)  
        {
            if ( pos[s[i]-'A'].size() > 1 )  pos[s[i]-'A'].emplace_back(n);
        }
        int ret = 0;
        for (int k=0; k<26; k++)
            for (int i=1; i<pos[k].size()-1; i++)
            {
                ret += (pos[k][i]-pos[k][i-1])*(pos[k][i+1]-pos[k][i]);
            }

        return ret;   
    }
};
