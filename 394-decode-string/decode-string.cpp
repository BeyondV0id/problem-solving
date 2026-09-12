#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<int> stk1;
        stack<string> stk2;
        string res = "";

        int num = 0;

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                stk1.push(num);
                stk2.push(res);
                res = "";
                num = 0;
            } else if (s[i] == ']') {
                int cnt = stk1.top();
                stk1.pop();
                string prev = stk2.top();
                stk2.pop();

                string repeat = "";
                for (int i = 0; i < cnt; i++) {
                    repeat += res;
                }
                res = prev + repeat;

            } else {
                res += s[i];
            }
        }
        return res;
    }
};
