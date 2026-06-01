// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0)
            return false;
        map<int, int> fq;
        for (auto& it : nums) {
            fq[it]++;
        }

        while (!fq.empty()) {
            int num = fq.begin()->first;
            for (int i = 0; i < k; i++) {
                int curr = num + i;
                if (fq[curr] == 0)
                    return false;

                fq[curr]--;
                if (fq[curr] == 0) {
                    fq.erase(curr);
                }
            }
        }
        return true;
    }
};
