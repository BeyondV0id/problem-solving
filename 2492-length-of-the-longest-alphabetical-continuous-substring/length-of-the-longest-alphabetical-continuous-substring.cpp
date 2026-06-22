// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int seq = 0;
        int n = s.size();
        int maxLen = INT_MIN;

        int l = 0;
        for (int r = 1; r < n; r++) {
            if (s[r] - s[r - 1] != 1) 
                l = r;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen == INT_MIN ? 1 : maxLen;
    }
};
