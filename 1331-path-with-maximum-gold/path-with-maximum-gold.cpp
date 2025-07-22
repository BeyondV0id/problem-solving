/*
 * @lc app=leetcode id=1219 lang=cpp
 *
 * [1219] Path with Maximum Gold
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
private:
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {1, 0, -1, 0};

    int maxGoldcnt = INT_MIN;
    void dfs(vector<vector<int>>& grid, int r, int c, const int R, const int C,
             int goldCnt, vector<vector<bool>>& visited) {
        if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] == 0 ||
            visited[r][c])
            return;
        visited[r][c] = true;
        goldCnt += grid[r][c];
        maxGoldcnt = max(goldCnt, maxGoldcnt);

        for (int i = 0; i < 4; i++) {
            int newR = r + dx[i];
            int newC = c + dy[i];
            dfs(grid, newR, newC, R, C, goldCnt, visited);
        }
        visited[r][c] = false;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        const int R = grid.size();
        const int C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                if (grid[r][c] != 0 && !visited[r][c]) {
                    dfs(grid, r, c, R, C, 0, visited);
                }
            }
        return maxGoldcnt==INT_MIN?0:maxGoldcnt;
    }
};
// @lc code=end
