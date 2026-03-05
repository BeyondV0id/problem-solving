class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sk;
        string res;
        for (char c : s) {
            if (!sk.empty() && sk.top() == c) {
                sk.pop();
            } else {
                sk.push(c);
            }
        }
        while (!sk.empty()) {
            char s = sk.top();
            sk.pop();
            res.push_back(s);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};