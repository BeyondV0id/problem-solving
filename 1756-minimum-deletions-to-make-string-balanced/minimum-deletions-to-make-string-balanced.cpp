class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int bSeen = 0; bSeen <= 1; bSeen++) {
                if (s[i] == 'a') {
                    if (bSeen == 1) {
                        dp[i][1] = 1 + dp[i + 1][1];
                    } else {
                        dp[i][0] = dp[i + 1][0];
                    }
                } else {
                    int keep = dp[i + 1][1];
                    int del  = 1 + dp[i + 1][bSeen];
                    dp[i][bSeen] = min(keep, del);
                }
            }
        }

        return dp[0][0];
    }
};