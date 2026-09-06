class Solution {
private:
    vector<vector<long long>> dp;

    long long tab(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<unsigned long long>> dp2(n + 1, vector<unsigned long long>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp2[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m && j <= i; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp2[i][j] += dp2[i - 1][j - 1] + dp2[i - 1][j];
                } else {
                    dp2[i][j] += dp2[i - 1][j];
                }
            }
        }
        return dp2[n][m];
    }
    long long backtrack(string s, string t, int i, int j) {

        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long cnt = 0;
        if (s[i] == t[j]) {
            // take
            cnt += backtrack(s, t, i + 1, j + 1);

            // nottake
            cnt += backtrack(s, t, i + 1, j);
        }

        else {
            cnt += backtrack(s, t, i + 1, j);
        }
        return dp[i][j] = cnt;
    }

public:
    int numDistinct(string s, string t) {

        return tab(s, t);

        //int n = s.size();
        //int m = t.size();

        //dp.assign(n + 1, vector<long long>(m + 1, -1));

        // return backtrack(s, t, 0, 0);
    }
};