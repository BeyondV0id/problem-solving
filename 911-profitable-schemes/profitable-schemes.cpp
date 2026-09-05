class Solution {
private:
    vector<vector<vector<long long>>> dp;
    const int MOD = 1e9 + 7;

    long long backtrack(int n, int minProfit, vector<int>& group, vector<int>& profit,
                  int i, int people, int totalProfit) {

        if (i == group.size()) {
            if (totalProfit >= minProfit) {
                return 1;
            }
            return 0;
        }

        if (dp[i][totalProfit][people] != -1) {
            return dp[i][totalProfit][people];
        }

        long long ans = 0;

        // NOT TAKE
        ans = (ans +
            backtrack(n, minProfit, group, profit, i + 1, people, totalProfit))%MOD;

        // TAKE
        if (people + group[i] <= n) {

            ans =
                (ans + backtrack(n, minProfit, group, profit, i + 1, people + group[i],
                          min(minProfit, totalProfit + profit[i]))) % MOD;
        }

        return dp[i][totalProfit][people] = ans;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {

        dp.assign(group.size() + 1,
                  vector<vector<long long>>(minProfit + 1, vector<long long>(n + 1, -1)));

        return backtrack(n, minProfit, group, profit, 0, 0, 0);
    }
};