#include <iostream>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    bool backtracking(string s1, string s2, string s3, int i, int j) {
        if (i + j == (int)s3.size())
            return i == (int)s1.size() && j == (int)s2.size();

        if (i > s1.size() || j > s2.size())
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s3[i + j] == s1[i]) {
            if (backtracking(s1, s2, s3, i + 1, j)) {
                return dp[i][j] = 1;
                //dp[i][j] = 1;
                //return 1;
            }
        }
        if (s3[i + j] == s2[j]) {
            if (backtracking(s1, s2, s3, i, j + 1)) {
                return dp[i][j] = 1;
            }
        }
        dp[i][j] = 0;
        return false;
        // return dp[i][j] = 0;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return backtracking(s1, s2, s3, 0, 0);
    }
};
