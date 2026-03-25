// @leet imports start
#include <bits/stdc++.h>
#include <mutex>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool flag = true;

        vector<long long> colSum(n, 0);
        vector<long long> rowSum(m, 0);

        long long totalSum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
                colSum[j] += grid[i][j];
                rowSum[i] += grid[i][j];
            }
        }
        if (totalSum % 2 != 0)
            return false;

        long long left = 0;
        for (int j = 0; j < n - 1; j++) {
            left += colSum[j];
            long long right = totalSum - left;
            if (left == right)
                return true;
        }

        long long top = 0;
        for (int i = 0; i < m - 1; i++) {
            top += rowSum[i];
            long long bot = totalSum - top;
            if (top == bot)
                return true;
        }
        return false;
    }
};
// @leet end
