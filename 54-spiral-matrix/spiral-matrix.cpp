class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int topWall = 0;
        int bottomWall = matrix.size() - 1;
        int rightWall = matrix[0].size() - 1;
        int leftWall = 0;
        int direction = 0;
        int totalElements = matrix.size()*matrix[0].size();

        while (res.size() < totalElements) {
            if (direction == 0) {
                for (int i = leftWall; i <= rightWall; i++) {
                    res.push_back(matrix[topWall][i]);
                }
                topWall++;
            } else if (direction == 1) {
                for (int i = topWall; i <= bottomWall; i++) {
                    res.push_back(matrix[i][rightWall]);
                }
                rightWall--;
            } else if (direction == 2) {
                for (int i = rightWall; i >= leftWall; i--) {
                    res.push_back(matrix[bottomWall][i]);
                }
                bottomWall--;
            } else if (direction == 3) {
                for (int i = bottomWall; i >= topWall; i--) {
                    res.push_back(matrix[i][leftWall]);
                }
             leftWall++;
            }
            direction = (direction + 1) % 4;
        }
        return res;
    }
};
// @lc code=end
