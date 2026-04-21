// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    bool backtrack(vector<int>& matchsticks, int i, vector<int>& sides,
                   int target) {
        if (i == (int)matchsticks.size()) {
            return sides[0] == target && sides[1] == target &&

                   sides[2] == target && sides[3] == target;
        }

        for (int j = 0; j < 4; j++) {
            if (sides[j] + matchsticks[i] <= target) {
                sides[j] += matchsticks[i];
                if (backtrack(matchsticks, i + 1, sides, target))
                    return true;
                sides[j] -= matchsticks[i];
                if (sides[j] == 0) break;
            }
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (auto& it : matchsticks) {
            sum += it;
        }
        sort(matchsticks.begin(),matchsticks.end());

        vector<int> sides(4, 0);
        if (sum % 4 != 0)
            return false;
        int side_len = sum / 4;
        return backtrack(matchsticks, 0, sides, side_len);
    }
};
// @leet end
