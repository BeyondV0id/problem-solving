// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start

class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<int> lower;
        unordered_set<int> upper;

        int cnt = 0;
        for (auto ch : word) {
            if (ch >= 'A' && ch <= 'Z') {
                upper.insert('A' - ch);
            } else {
                lower.insert('a' - ch);
            }
        }
        for (auto x : lower) {
            if (upper.count(x)) {
                cnt++;
            }
        }
        return cnt;
    }
};
