// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
  int helper(vector<int>&nums,int start,int end){
    int n = nums.size();
    vector<int>dp(n+2,0);
      for(int i = end; i >= start; i--){
        int take = nums[i] + dp[i+2];
        int leave = dp[i+1];
        dp[i] = max(take,leave);
      }
      return dp[start];
  }
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if (n == 1)return nums[0];
      vector<int>dp(n+2,0);
      //skip 0th index then we have 1 -> n - 1 
      int res = helper(nums,1,n-1);
      //skip n-1th index.then we have 0 -> n - 2
      res = max(res,helper(nums,0,n-2));
      return res;
    }
};
// @leet end

