// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeroes(n);

        for (int i = 0; i < n; i++) {
            int zeroCnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    zeroCnt++;
                } else {
                    break;
                }
            }
            trailingZeroes[i] = zeroCnt;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int needed = n - 1 - i;
            int j = i;

            while (j < n && trailingZeroes[j] < needed) {
                j++;
            }

            if (j == n)
                return -1;

            while (j > i) {
                swap(trailingZeroes[j], trailingZeroes[j - 1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};
// @leet end