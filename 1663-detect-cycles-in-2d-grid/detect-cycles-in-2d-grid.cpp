class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py,
             vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        vis[x][y] = 1;

        for (auto [nx, ny] : dirs) {
            int dx = nx + x;
            int dy = ny + y;

            if (dx >= m || dx < 0 || dy >= n || dy < 0)
                continue;

            if (grid[dx][dy] != grid[x][y])
                continue;

            // visited and not coming from parent
            if (vis[dx][dy] && (px != dx || py != dy))
                return true;

            if (!vis[dx][dy] && dfs(grid, dx, dy, x, y, vis))
                return true;
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, i, j, -1, -1, vis))
                        return true;
                }
            }
        }
        return false;
    }
};