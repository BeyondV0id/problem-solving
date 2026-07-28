#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
private:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        grid[i][j] = '0';

        for (auto [dx, dy] : dirs) {
            int x = dx + i;
            int y = dy + j;
            if (x >= m || y >= n || x < 0 || y < 0)
                continue;
            if (grid[x][y] == '1')
                dfs(grid, x, y);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
