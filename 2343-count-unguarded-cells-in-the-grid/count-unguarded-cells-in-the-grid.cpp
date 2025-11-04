// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int res = 0;
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (const auto& g : guards) {
            int x = g[0];
            int y = g[1];
            grid[x][y] = 1;
        }
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& wall : walls) {
            int x = wall[0];
            int y = wall[1];
            grid[x][y] = 2;
        }
        for (auto& g : guards) {
            int x = g[0], y = g[1];
            for (auto& [dx, dy] : dirs) {
                int i = x + dx, j = y + dy;
                while (i >= 0 && i < m && j >= 0 && j < n &&
                       (grid[i][j] != 1 && grid[i][j] != 2)) {
                    if (grid[i][j] == 0)
                        grid[i][j] = 3;
                    i += dx;
                    j += dy;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    res++;
            }
        }
        return res;
    }
};
// @leet end
