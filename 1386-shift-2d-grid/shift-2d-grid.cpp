class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> flat;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                flat.push_back(grid[row][col]);
            }
        }

        int totalElements = flat.size();
        k %= totalElements;

        vector<int> shifted(totalElements);

        for (int i = 0; i < totalElements; i++) {
            shifted[(i + k) % totalElements] = flat[i];
        }

        vector<vector<int>> result(rows, vector<int>(cols));

        int index = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                result[row][col] = shifted[index++];
            }
        }

        return result;
    }
};