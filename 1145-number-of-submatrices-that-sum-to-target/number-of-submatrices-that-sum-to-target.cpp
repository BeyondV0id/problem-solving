// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    int matrixPrefixSum = 0;
    int res = 0;

public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> prefixMatrix(matrix.size(),
                                         vector<int>(matrix[0].size(), 0));

        for (int r = 0; r < (int)matrix.size(); r++) {
            for (int c = 0; c < (int)matrix[0].size(); c++) {
                int top = r > 0 ? prefixMatrix[r - 1][c] : 0;
                int left = c > 0 ? prefixMatrix[r][c - 1] : 0;
                int cross = (r > 0 && c > 0) ? prefixMatrix[r - 1][c - 1] : 0;
                prefixMatrix[r][c] = matrix[r][c] + top + left - cross;
            }
        }

        for (int r1 = 0; r1 < (int)matrix.size(); r1++) {
            for (int r2 = r1; r2 < (int)matrix.size(); r2++) {
                for (int c1 = 0; c1 < (int)matrix[0].size(); c1++) {
                    for (int c2 = c1; c2 < (int)matrix[0].size(); c2++) {

                        int currSum = prefixMatrix[r2][c2];
                        if (r1 > 0)
                            currSum -= prefixMatrix[r1 - 1][c2];
                        if (c1 > 0)
                            currSum -= prefixMatrix[r2][c1 - 1];
                        if (r1 > 0 && c1 > 0)
                            currSum += prefixMatrix[r1 - 1][c1 - 1];

                        if (currSum == target)
                            res++;
                    }
                }
            }
        }

        return res;
    }
};
// @leet end
