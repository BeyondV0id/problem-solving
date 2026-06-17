// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start

class Solution {
  private:
    int backtrack(int indx, vector<int> &arr, int k, vector<int>&dp) {
        int n = arr.size();
        if (indx >= n) {
          return 0;
        }
        if(dp[indx] != -1)return dp[indx];

        int curMax = 0;
        int maxSum = 0;
        for (int i = 1; i <= k && indx + i <= n; i++) {
            curMax = max(curMax, arr[indx + i - 1]);
            maxSum = max(maxSum, curMax*i + backtrack(indx+i,arr,k,dp));
        }
        return dp[indx] = maxSum;
    }

  public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return backtrack(0,arr,k,dp);
    }
};
