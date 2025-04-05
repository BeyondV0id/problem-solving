// Last updated: 4/5/2025, 9:12:35 AM
class Solution {
public:
    static constexpr int outOfBounds{-1};

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<bool>> mem(grid.size());
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                mem[i].push_back(false);
            }
        }

        return findPath(grid, mem);
    }

    int findPath(vector<vector<int>>& grid, vector<vector<bool>>& mem,
                 int i = 0, int j = 0) {
        if (i >= grid[0].size() || j >= grid.size())
            return outOfBounds;
        else if (i == grid[0].size() - 1 && j == grid.size() - 1)
            return grid[j][i];
        else if (mem[j][i])
            return grid[j][i];

        int right = findPath(grid, mem, i + 1, j);
        int left = findPath(grid, mem, i, j + 1);
        mem[j][i] = true;
        
        if (right == outOfBounds)
            return grid[j][i] += left;
        else if (left == outOfBounds)
            return grid[j][i] += right;
        else
            return left < right ? (grid[j][i] += left) : (grid[j][i] += right);
    }
};