class Solution {
private:
    vector<vector<int>> dist;
    vector<pair<int, int>> dirs = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    queue<pair<int, int>> q;

    void bfs(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& [nx, ny] : dirs) {
                int dx = x + nx;
                int dy = y + ny;

                if (dx >= 0 && dx < m &&
                    dy >= 0 && dy < n &&
                    dist[dx][dy] == -1) {

                    dist[dx][dy] = 1 + dist[x][y];
                    q.push({dx, dy});
                }
            }
        }
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dist.resize(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        bfs(grid);


        priority_queue<pair<int, pair<int, int>>> pq;

 
        pq.push({dist[0][0], {0, 0}});

        vector<vector<int>> vis(m, vector<int>(n, 0));

        while (!pq.empty()) {

            auto [safety, pos] = pq.top();
            pq.pop();

            auto [r, c] = pos;

            if (vis[r][c])
                continue;

            vis[r][c] = 1;


            if (r == m - 1 && c == n - 1) {
                return safety;
            }

            for (auto& [dr, dc] : dirs) {

                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !vis[nr][nc]) {

                    int newSafety =
                        min(safety, dist[nr][nc]);

                    pq.push({
                        newSafety,
                        {nr, nc}
                    });
                }
            }
        }

        return -1;
    }
};