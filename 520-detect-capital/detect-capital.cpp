// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = false;
        bool allSmall = true;
        bool allCapital = true;
        char start = word[0];
        int n = word.size();

        if (start >= 'A' && start <= 'Z') {
            flag = true;
        }

        for (int i = 1; i < n; i++) {
            char ch = word[i];
            if (ch >= 'A' && ch <= 'Z') {
                allSmall = false;
            } else {
                allCapital = false;
            }
        }
        if (flag && allSmall) {
            return true;
        }
        if (flag && allCapital) {
            return true;
        }
        if (!flag && allSmall) {
            return true;
        }
        return false;
    }
};
