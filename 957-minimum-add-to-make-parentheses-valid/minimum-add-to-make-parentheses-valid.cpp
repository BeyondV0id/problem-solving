/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;
class Solution {
private:
    stack<char> stk;

public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        for (auto& ch : s) {
            if (ch == '(')
                stk.push(ch);
            else if (ch == ')') {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    cnt++;
            }
        }
        return cnt + stk.size();
    }
};
// @lc code=end
