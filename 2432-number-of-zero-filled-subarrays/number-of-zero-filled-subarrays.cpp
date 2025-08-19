// @leet imports start
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        long long cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                cnt++;
            else {
                res += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }
        res += cnt * (cnt + 1) / 2;
        return res;
    }
};
// @leet end
