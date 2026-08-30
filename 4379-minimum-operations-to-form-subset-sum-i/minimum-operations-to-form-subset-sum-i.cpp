class Solution {
private:
    vector<vector<int>> dp;
    int INF = 1e9;
    int solve(vector<int>& nums, int indx, int curSum) {
        if (curSum == 0)
            return 0;
        if(curSum < 0)return INF;
        if (indx == nums.size())
            return INF;

        if (dp[indx][curSum] != -1)
            return dp[indx][curSum];

        int ans = INF;

        int notTake = solve(nums, indx + 1, curSum);

        ans = min(ans, notTake);
        int take;

        if (nums[indx] <= curSum) {
            take = solve(nums, indx + 1, curSum - nums[indx]);
            ans = min(ans, take);
        }

        // multiply

        int ops = 0;
        long long num = nums[indx];

        while (num <= curSum) {
            num *= 2;
            ops++;
            take = solve(nums, indx + 1, curSum - num);
            ans = min(ans, ops + take);
        }

        ops = 0;

        num = nums[indx];

        while (num > 0) {
            num /= 2;
            ops++;
            take = solve(nums,indx+1,curSum-num);
            ans = min(ans,ops+take);
        }

        return dp[indx][curSum] = ans;
    }

public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        dp.assign(n, vector<int>(sum + 1, -1));
        int ans = solve(nums,0,sum);

        return ans == INF? -1 : ans;
    }
};