class Solution {
private:
    int res = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int r, int c, int R, int C, long long &cnt,
             vector<vector<bool>> &visited) {
        if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] == 0)
            return;
        if (visited[r][c])
            return;
        cnt += grid[r][c];
        visited[r][c] = true;
        for (auto [dr, dc] : directions) {
            dfs(grid, r + dr, c + dc, R, C, cnt, visited);
        }
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        const int R = grid.size();
        const int C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                if (grid[r][c] != 0 && !visited[r][c]) {
                    long long  cnt = 0;
                    dfs(grid, r, c, R, C, cnt, visited);
                    if (cnt % k == 0)
                        res++;
                }
            }
        return res;
    }
};