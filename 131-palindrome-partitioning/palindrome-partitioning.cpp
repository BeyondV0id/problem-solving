// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<vector<string>> res;
    vector<string> sub;
    bool isPalindrom(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string s, int indx) {
        if (indx == (int)s.size()) {
            res.push_back(sub);
            return;
        }
        for (int i = indx; i < (int)s.size(); i++) {
            if (isPalindrom(s, indx, i)) {
                sub.push_back(s.substr(indx, i - indx + 1));
                backtrack(s, i + 1);
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};
// @leet end

