/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
private:
    stack<int> stk;
    stack<string> strstk;
    string cur = "";
    string num = "";

public:
    string decodeString(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                while (i < n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                i--;
                stk.push(stoi(num));
                num = "";
            }
            else if (s[i] == '[') {
                strstk.push(cur);
                cur = "";
            }
            else if (s[i] == ']') {
                string prev = "";
                if (strstk.empty())
                    prev = "";
                else
                    prev = strstk.top();
                string temp = "";
                int cnt = stk.top();
                stk.pop();
                strstk.pop();
                for (int i = 0; i < cnt; i++) {
                    temp += cur;
                }
                cur = prev + temp;
            } else {
                cur += s[i];
            }
        }
        return cur;
    }
};
// @lc code=end
