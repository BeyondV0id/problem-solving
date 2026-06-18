class Solution {
    int helper(vector<vector<char>>& matrix, int i, int j, int m, int n,
               vector<vector<int>>& dp) {
        if (i >= m || j >= n) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (matrix[i][j] == '0') {
            return dp[i][j] = 0;
        }

        int right = helper(matrix, i, j + 1, m, n, dp);
        int down = helper(matrix, i + 1, j, m, n, dp);
        int cross = helper(matrix, i + 1, j + 1, m, n, dp);

        return dp[i][j] = 1 + min({right, down, cross});;

    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, helper(matrix, i, j, m, n, dp));
            }
        }
        return maxi * maxi;
    }
};