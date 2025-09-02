// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    int maxL = 0, maxR = 0;

public:
    int maxDistance(vector<int>& colors) {
        int minLeft = 0;
        int maxRight = colors.size() - 1;
        for (int i = 1; i < (int)colors.size(); i++) {
            if (colors[i] != colors[minLeft])
                maxL = max(maxL, i - minLeft);
        }
        for (int i = colors.size() - 1; i >= 0; i--) {
            if (colors[i] != colors[maxRight])
                maxR = max(maxR, maxRight - i);
        }
        return max(maxL, maxR);
    }
};
// @leet end

