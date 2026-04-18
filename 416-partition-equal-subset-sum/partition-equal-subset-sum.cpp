// @leet imports start
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    bool rec(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (i == 0)
            return (nums[i] == target);
        if (dp[i][target] != -1)
            return dp[i][target];
        bool notTake = rec(i - 1, target, nums, dp);

        bool take = false;

        if (nums[i] <= target) {
            take = rec(i - 1, target - nums[i], nums, dp);
        }

        return dp[i][target] = (take || notTake);
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto& it : nums) {
            sum += it;
        }
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return rec(n - 1, target, nums, dp);
    }
};
