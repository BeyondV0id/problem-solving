// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int minPairSum(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      int maxPair = INT_MIN;
      for(int i = 0; i < (int)n/2; i++){
        maxPair = max(maxPair,nums[i]+nums[n-i-1]);
      }
      return maxPair;
    }
};
// @leet end
