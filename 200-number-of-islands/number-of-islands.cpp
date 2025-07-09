/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int cnt = 0;
    vector<pair<int, int>> directions = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
    };
    void dfs(vector<vector<char>>& grid, const int rows, const int cols, int r,
             int c) {
        if (r >= rows || c >= cols || r < 0 || c < 0)
            return;
        if (grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        for (auto [dr, dc] : directions) {
            dfs(grid, rows, cols, r + dr, c + dc);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, rows, cols, r, c);
                    cnt++;
                }
            }
        return cnt;
    }
};
// @lc code=end
