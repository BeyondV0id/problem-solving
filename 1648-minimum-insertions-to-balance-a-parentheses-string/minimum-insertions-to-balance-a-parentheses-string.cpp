class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        int open = 0;
        int cnt = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                open++;
                i++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    cnt++;
                }

                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    cnt++;
                    i++;
                }
            }
        }

        return cnt + open * 2;
    }
};