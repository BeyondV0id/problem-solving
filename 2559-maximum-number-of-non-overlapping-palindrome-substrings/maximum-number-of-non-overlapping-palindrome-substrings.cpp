class Solution {
private:
    vector<vector<int>> dp;

    bool isPal(string& s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int backtrack(string& s, int k, int i, int j) {
        if (j >= s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int grow = backtrack(s, k, i, j + 1);
        int slide = backtrack(s, k, i + 1, j + 1);

        if (isPal(s, i, j)) {
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

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return backtrack(s, k, 0, k - 1);
    }
};