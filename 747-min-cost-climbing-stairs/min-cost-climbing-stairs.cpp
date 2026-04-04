class Solution {
    vector<int> dp;
    int backtrack(vector<int>& cost, int indx) {
        int n = cost.size();
        if (indx >= n)
            return 0;
        if (dp[indx] != -1) {
            return dp[indx];
        }
        int total = cost[indx] +
                    min(backtrack(cost, indx + 1), 
                    backtrack(cost, indx + 2));
        return dp[indx] = total;
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp = vector<int>(n, -1);
        return min(backtrack(cost, 0), backtrack(cost, 1));
    }
};