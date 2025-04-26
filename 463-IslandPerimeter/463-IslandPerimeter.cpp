// Last updated: 4/26/2025, 2:50:32 PM
/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                cnt += 4;
                if (i > 0 && grid[i - 1][j] == 1)
                    cnt -= 2;
                if (j > 0 && grid[i][j - 1] == 1)
                    cnt -= 2;
            }
        return cnt;
    }
};
// @lc code=end
