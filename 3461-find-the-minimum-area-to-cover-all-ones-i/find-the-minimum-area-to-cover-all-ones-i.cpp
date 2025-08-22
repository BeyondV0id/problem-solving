// @leet imports start
#include <bits/stdc++.h>
#include <climits>
using namespace std;
// @leet imports end

// @leet start
class Solution {
  public:
    int minimumArea(vector<vector<int>> &grid) {
        int R = grid.size();
        int C = grid[0].size();
        int top = INT_MAX, left = INT_MAX;
        int bottom = INT_MIN, right = INT_MIN;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1) {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    right = max(right, j);
                    left = min(left, j);
                }
            }
        int height = (bottom - top + 1);
        int width = (right - left + 1);
        return height * width;
    }
};
// @leet end
