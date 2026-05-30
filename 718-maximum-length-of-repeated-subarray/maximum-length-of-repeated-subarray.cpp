#include <bits/stdc++.h>
// @leet imports start
using namespace std;
// @leet imports end

// @leet start

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size();
      int n = nums2.size();
      vector<vector<int>>dp(m+1,vector<int>(n+1));
      int maxLen = INT_MIN;

      for(int i = 1; i <= m; i++){
        for(int j = 1; j <=n; j++){
          if(nums1[i-1] == nums2[j-1]){
            dp[i][j] = dp[i-1][j-1]+1;
          }
          maxLen = max(maxLen,dp[i][j]) ;
        }
      }
        
      return maxLen;
    }
};
