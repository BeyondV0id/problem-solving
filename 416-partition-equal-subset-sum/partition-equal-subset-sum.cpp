class Solution {
private:
    bool rec(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (i == nums.size())
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool notTake = rec(i + 1, target, nums, dp);

        bool take = false;

        if (nums[i] <= target) {
            take = rec(i + 1, target - nums[i], nums, dp);
        }

        return dp[i][target] = (take || notTake);
    }

public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        for (auto& it : nums)
            sum += it;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return rec(0, target, nums, dp);
    }
};