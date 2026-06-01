// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    pair<int, int> count(string& s) {
        int zeroes = 0;
        int ones = 0;
        for (char c : s) {
            if (c == '0')
                zeroes++;
            else
                ones++;
        }
        return {zeroes, ones};
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto& s : strs) {
            auto [zeroes, ones] = count(s);
            for (int i = m; i >= 0; i--) {
                for (int j = n; j >= 0; j--) {
                    if (i >= zeroes && j >= ones) {
                        dp[i][j] = max(dp[i][j], dp[i - zeroes][j - ones] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};

// @leet end

