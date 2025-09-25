// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        for (int i = 1; i < (int)triangle.size(); i++) {
            for (int j = 0; j < (int)triangle[i].size(); j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == (int)triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] +=
                        min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        auto minNo =
            min_element(triangle[size - 1].begin(), triangle[size - 1].end());
        return *minNo;
    }
};
// @leet end
