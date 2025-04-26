// Last updated: 4/26/2025, 4:15:52 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> zerolocs;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    zerolocs.push_back({i, j});

        for (auto& z : zerolocs) {
            int x = z.first;
            int y = z.second;
            for (int i = 0; i < m; i++)
                matrix[i][y] = 0;
            for (int j = 0; j < n; j++)
                matrix[x][j] = 0;
        }
    }
};
// @lc code=end
