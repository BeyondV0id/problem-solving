class Solution {
private:
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0)
            return 1;

        if (dp[target] != -1)
            return dp[target];

        int ways = 0;

        for (int num : nums) {
            if (num <= target)
                ways += solve(nums, target - num, dp);
        }

        return dp[target] = ways;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};