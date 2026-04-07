// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
  int backtrack(vector<vector<int>>&obstacleGrid,int i, int j, int M,int N,vector<vector<int>>&dp){
    if(i >= M || j >= N)return 0;

    if(dp[i][j] != -1)return dp[i][j];
    if(obstacleGrid[i][j] == 1)return 0;

    if(i == M-1 && j == N-1){
      return 1;
    }

    dp[i][j] = backtrack(obstacleGrid,i+1,j,M,N,dp) + backtrack(obstacleGrid,i,j+1,M,N,dp);
    return dp[i][j];
  }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int M = obstacleGrid.size();
      int N = obstacleGrid[0].size();

      vector<vector<int>>dp(M,vector<int>(N,-1));

      if(M == 1 && N == 1)return obstacleGrid[0][0] == 0 ? 1 : 0;
      if(obstacleGrid[0][0])return 0;
      backtrack(obstacleGrid,0,0,M,N,dp);
      return dp[0][0];

    }
};
// @leet end

