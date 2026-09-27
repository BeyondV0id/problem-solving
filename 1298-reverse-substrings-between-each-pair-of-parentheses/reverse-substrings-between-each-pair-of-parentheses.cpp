class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        int n = s.size();

        stack<int> stk; // store indexes

        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                stk.push(i);

            else if (s[i] == ')') {
                int indx = stk.top();
                stk.pop();
                int len = i - indx - 1;
                string sub = s.substr(indx + 1, len);

                reverse(sub.begin(), sub.end());
                s.replace(indx + 1, len, sub);
            }
        }
        string ans = "";

        for (char c : s) {
            if (c != '(' && c != ')')
                ans += c;
        }

        return ans;
    }
};