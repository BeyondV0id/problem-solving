class Solution {

private:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool canReach(vector<vector<int>>& grid, int t) {

        int n = grid.size();

        if (grid[0][0] > t) {
            return false;
        }
        queue<pair<int, int>> q;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    !visited[nr][nc] && grid[nr][nc] <= t) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        int maxxi = INT_MIN;

        for (auto& row : grid) {
            maxxi = max(maxxi, *max_element(row.begin(), row.end()));
        }
        int lastVal = grid[n - 1][n - 1];

        int low = lastVal;
        int high = maxxi;

        int ans = high;

        while (low <= high) {
            int t = low + (high - low) / 2;

            if (canReach(grid, t)) {
                high = t - 1;
                ans = t;
            } else {
                low = t + 1;
            }
        }
        return ans;
    }
};