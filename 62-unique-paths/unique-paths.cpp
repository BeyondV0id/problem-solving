// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    // int backtrack(int i,int j,int m,int n){
    //   if(i >= m || j >= n)return 0;
    //   if(i == m-1 && j == n-1){
    //     return 1;
    //   }
    //   return backtrack(i+1,j,m,n) + backtrack(i,j+1,m,n);
    // }
    int backtrack(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] =
            backtrack(m, n, i + 1, j, dp) + backtrack(m, n, i, j + 1, dp);
        return dp[i][j];
    }

public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1)
            return 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        backtrack(m, n, 0, 0, dp);
        return dp[0][0];
    }
};
