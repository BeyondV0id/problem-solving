class Solution {
public:
    string finalString(string s) {
        string res = "";
        
        for (char ch : s) {
            if (ch == 'i') {
                reverse(res.begin(), res.end());
            } else {
                res += ch;
            }
        }
        
        return res;
    }
};