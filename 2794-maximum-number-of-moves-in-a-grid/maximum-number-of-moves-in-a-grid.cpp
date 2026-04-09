// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 1}, {0, 1}, {-1, 1}};

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = n - 2; j >= 0; j--){
            for (int i = m - 1; i >= 0; i--) {
                for (auto& it : dirs) {
                    int x = i + it.first;
                    int y = j + it.second;

                    if (x >= 0 && y >= 0 && x <= m - 1 && y <= n - 1 &&
                        grid[x][y] > grid[i][j]) {
                        dp[i][j] = max(dp[i][j], 1 + dp[x][y]);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};
// @leet end
