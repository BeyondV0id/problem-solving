class Solution {
private:
    vector<long long> dp;
    long long memo(int n) {
        if (n == 1) {
            return 0;
        }
        long long cost = INT_MAX;
        for (int i = 1; i < n; i++) {
            cost = min(cost, (i)*(n-i) + memo(i) + memo(n-i));
        }
        return dp[n] = cost;
    }
    int solve(int n) {
        if (n == 1)
            return 0;

        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            int cost = (n - i) * i + solve(i) + solve(n - i);

            ans = min(ans, cost);
        }
        return ans;
    }

public:
    int minCost(int n) {
        //dp.assign(n + 1, -1);
        dp.assign(n+1,INT_MAX);
        dp[1] = 0;
    
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                long long cost = (j)*(i-j);

                dp[i] = min(dp[i], cost + dp[j] + dp[i-j]);
                 
            }
        }
        return dp[n];
    }
};