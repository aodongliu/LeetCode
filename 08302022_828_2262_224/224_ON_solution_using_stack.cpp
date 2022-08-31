class Solution {
public:
    int calculate(string s) {
        
        int n = s.length();
        int sum = 0;
        int sign = 1;
        stack<int> a; 
        for(int i = 0; i < n ; ++i)
        {
            // if we encounter a number
            if(s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9')
                {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i--;
                sum += sign * num;
            } else if (s[i] == '+'){
                sign = 1;
            } else if (s[i] == '-'){
                sign = -1;
            } else if (s[i] == '('){
                a.push(sum);
                a.push(sign);
                sum = 0;
                sign = 1;
            } else if (s[i] == ')'){
                // the top of stack is the sign
                sum *= a.top();
                a.pop();
                // then add the previous result prior to the '('
                sum += a.top();
                a.pop();
            }
        }
        return sum;
        
    }
};
