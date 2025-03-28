// Last updated: 3/28/2025, 4:36:06 PM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        double angle = -M_PI / 2;
        vector<vector<int>> result = matrix;
        double cx = (n - 1) / 2.0;
        double cy = (n - 1) / 2.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double x = i - cx;
                double y = j - cy;
                int newX = round(cx + (x * cos(angle) - y * sin(angle)));
                int newY = round(cy + (x * sin(angle) + y * cos(angle)));
                result[newX][newY] = matrix[i][j];
            }
        }
        matrix = result;
    }
};