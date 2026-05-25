// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;

        while (label >= 1) {
            res.push_back(label);

            int level = log2(label) + 1;

            int startIndx = pow(2, level - 1);
            int lastIndx = pow(2, level) - 1;

            bool isRev = (level % 2 == 0);

            if (isRev) {
                label = lastIndx - label; // relative index (15-14 == 1)
                label =
                    startIndx + label; // add relative index to start 8+1 = 9
            }
            label /= 2;

            if (label == 0)
                break;
            int parentLevel = level - 1;

            if (parentLevel % 2 == 0) {

                int parentStart = pow(2, parentLevel - 1);
                int parentLast = pow(2, parentLevel) - 1;

                int indx = label - parentStart;

                label = parentLast - indx;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
