class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totalElements = rows * cols;

        k %= totalElements;

        vector<vector<int>> shiftedGrid(rows, vector<int>(cols));

        for (int i = 0; i < totalElements; i++) {
            int newPosition = (i + k) % totalElements;

            int currentRow = i / cols;
            int currentCol = i % cols;

            int newRow = newPosition / cols;
            int newCol = newPosition % cols;

            shiftedGrid[newRow][newCol] = grid[currentRow][currentCol];
        }

        return shiftedGrid;
    }
};