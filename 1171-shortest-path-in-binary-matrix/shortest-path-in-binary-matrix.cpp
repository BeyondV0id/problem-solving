class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1},   {1, 0}, {-1, 0}, {0, -1},
                                   {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int len = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n - 1 && y == n - 1)
                    return len;

                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    if (grid[nx][ny] == 1)
                        continue;

                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

            len++;
        }

        return -1;
    }
};