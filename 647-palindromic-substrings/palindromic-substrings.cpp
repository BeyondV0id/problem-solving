// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int countSubstrings(string s) {
        int m = s.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        int cnt = 0;

        for (int gap = 0; gap < m; gap++) {
            for (int i = 0; i < m - gap; i++) {
                int j = i + gap;
                if (s[i] == s[j]) {
                    if (gap <= 2) {
                        dp[i][j] = 1;
                    } else {
                        if (dp[i + 1][j - 1] == 1) {
                            dp[i][j] = 1;
                        }
                    }
                }
                if (dp[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
// @leet end
