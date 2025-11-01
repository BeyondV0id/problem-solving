// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<pair<int, int>> dvector = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int R, int C, int r, int c,
            bool& isSafe) {
        if (r < 0 || c < 0 || r >= R || c >= C || grid[r][c] != 1)
            return 0;
        if (r == 0 || r == R - 1 || c == 0 || c == C - 1)
            isSafe = true;
        int cnt = 1;
        grid[r][c] = 0;
        for (auto [dr, dc] : dvector) {
            cnt += dfs(grid, R, C, r + dr, c + dc, isSafe);
        }
        return cnt;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        int R = grid.size();
        int C = grid[0].size();
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                bool isSafe = false;
                if (grid[r][c] == 1) {
                    int island = dfs(grid, R, C, r, c, isSafe);
                    if (!isSafe)
                        cnt += island;
                }
            }
        }
        return cnt;
    }
};
// @leet end
