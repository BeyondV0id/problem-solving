// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    int emptyCells = 0;
    int paths = 0;
    void backtrack(vector<vector<int>>& grid, int i, int j, int count) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == -1) {
            return;
        }
        if (grid[i][j] == 2) {
            if (count == emptyCells) {
                paths++;
                return;
            }
        }

        int tmp = grid[i][j];
        grid[i][j] = -1;

        backtrack(grid, i + 1, j, count + 1);
        backtrack(grid, i, j + 1, count + 1);
        backtrack(grid, i - 1, j, count + 1);
        backtrack(grid, i, j - 1, count + 1);

        grid[i][j] = tmp;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int startX = -1, startY = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] != -1) {
                    emptyCells++;
                }
            }
        }

        backtrack(grid, startX, startY, 1);
        return paths;
    }
};
// @leet end
