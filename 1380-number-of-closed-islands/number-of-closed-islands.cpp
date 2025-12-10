#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<pair<int,int>> directions{{1,0},{0,1},{-1,0},{0,-1}};

    int dfs(vector<vector<int>>& grid, int r, int c, int R, int C) {
      if (grid[r][c] == 1)
            return 1;
        if (r == 0 || r == R - 1 || c == 0 || c == C - 1)
            return 0;

        grid[r][c] = 1;
        int isClosed = 1;

        for (auto [dr, dc] : directions) {
            int dx = r + dr, dy = c + dc;
            if (!dfs(grid, dx, dy, R, C))
                isClosed = 0;
        }
        return isClosed;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int res = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 0)
                    res += dfs(grid, r, c, R, C);
            }
        }
        return res;
    }
};
