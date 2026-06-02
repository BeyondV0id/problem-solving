// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    bool backtrack(vector<int>& nums, int current, int indx, int k, int target,
                   vector<bool>& used) {

        if (k == 1)
            return true;

        if (current == target) {
            return backtrack(nums, 0, 0, k - 1, target, used);
        }

        for (int i = indx; i < (int)nums.size(); i++) {

            if (used[i])
                continue;

            if (nums[i] + current > target)
                continue;

            used[i] = true;

            if (backtrack(nums, current + nums[i], i + 1, k, target, used))
                return true;

            used[i] = false;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0)
            return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        vector<bool> used(nums.size());

        int indx = 0;
        int curr = 0;

        return backtrack(nums, curr, indx, k, target, used);
    }
};
// @leet end