class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int flag = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                open++;
            else {
                if (open > 0) {
                    open--;
                } else
                    close++;
            }
        }

        return abs(open + close);
    }
};