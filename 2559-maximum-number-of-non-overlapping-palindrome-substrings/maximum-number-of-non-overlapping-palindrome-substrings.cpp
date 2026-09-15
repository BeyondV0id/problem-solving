class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<bool>> isPalindrome;

    int backtrack(string& s, int k, int i, int j) {
        int n = s.size();

        if (i >= n || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int grow = backtrack(s, k, i, j + 1);
        int slide = backtrack(s, k, i + 1, j + 1);

        if (isPalindrome[i][j]) {
            int take = 1 + backtrack(s, k, j + 1, j + k);
            return dp[i][j] = max(take, max(grow, slide));
        }

        return dp[i][j] = max(grow, slide);
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        if (k == 1)
            return n;

        if (k > n)
            return 0;

        dp.assign(n + 1, vector<int>(n + 1, -1));
        isPalindrome.assign(n + 1, vector<bool>(n + 1, false));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    isPalindrome[i][j] = true;
                } else if (i + 1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] =
                        (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
                }
            }
        }

        return backtrack(s, k, 0, k - 1);
    }
};