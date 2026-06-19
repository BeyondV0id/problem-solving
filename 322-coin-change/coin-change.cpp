// @leet imports start
#include <bits/stdc++.h>
#include <climits>
using namespace std;
// @leet imports end

// @leet start
class Solution {
  private:
    int solve(vector<int> &coins, int amount, vector<int> &dp) {

      if(amount == 0)return 0;
      if(amount < 0)return 1e9;
      int n = coins.size();
      if(dp[amount] != -1)return dp[amount];

      int mini = 1e9;
      for(int i = 0; i < n; i++){
        if(coins[i] <= amount){
          mini = min(mini,1 + solve(coins,amount-coins[i],dp));
        }
      }
      return dp[amount] = mini;
    }

  public:
    int coinChange(vector<int> &coins, int amount) {
      int n = coins.size();
      vector<int>dp(amount+1,-1);
      int ans = solve(coins,amount,dp);
      return ans >= 1e9 ? -1 : ans;
    }
};
// @leet end
