// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int catchFish(vector<vector<int>>& grid, int r, int c, int R, int C) {
        if (r >= R || c >= C || c < 0 || r < 0)
            return 0;
        if (grid[r][c] == 0)
            return 0;
        int totalCatchedFishes = grid[r][c];
        grid[r][c] = 0;
        for (auto& [dr, dc] : dirs) {
            totalCatchedFishes += catchFish(grid, r + dr, c + dc, R, C);
        }
        return totalCatchedFishes;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxCatchtedFishes = 0;
        int R = grid.size();
        int C = grid[0].size();
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] != 0) {
                    maxCatchtedFishes =
                        max(maxCatchtedFishes, catchFish(grid, r, c, R, C));
                }
            }
        }
        return maxCatchtedFishes;
    }
};
// @leet end
