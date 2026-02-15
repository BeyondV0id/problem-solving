// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
    // private:
    //   int rec(vector<int>&nums,int currIndx){
    //     if(currIndx > (int)nums.size())return 0;
    //     int take = nums[currIndx] + rec(nums,currIndx+2);
    //     int skip = rec(nums,currIndx+1);
    //     return max(take,skip);
    //   }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0];
    }
};
// @leet end
