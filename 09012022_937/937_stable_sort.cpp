// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// Practice using std::sort with a lambda function
// The code itself is pretty self-explanatory

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        
            stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2){
            // Define our sorting logic in this lambda function:
            int index1 = log1.find(' ');
            string id1 = log1.substr(0, index1);
            string main1 = log1.substr(index1+1);
            
            int index2 = log2.find(' ');
            string id2 = log2.substr(0, index2);
            string main2 = log2.substr(index2+1);
            
            bool isDigit1 = isdigit(main1[0]);
            bool isDigit2 = isdigit(main2[0]);
            
            
            if( !isDigit1 && !isDigit2){
                
                int value = main1.compare(main2);
                if (value == 0) value = id1.compare(id2);
                return value < 0;
            }
            
            return isDigit1 ? false : (isDigit2? true: false);
            
        });
        return logs;
    }
};
