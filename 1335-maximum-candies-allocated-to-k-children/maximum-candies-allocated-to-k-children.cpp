// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    int res = 0;
    bool canDistributeCandies(vector<int>& candies, int assumedCandies,
                              long long k) {
        long long assumedCnt = 0;
        for (int i = 0; i < (int)candies.size(); i++) {
            assumedCnt += candies[i] / assumedCandies;
        }
        return assumedCnt >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int h = *max_element(candies.begin(), candies.end());
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (canDistributeCandies(candies, mid,k)) {
                res = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return res;
    }
};
// @leet end
