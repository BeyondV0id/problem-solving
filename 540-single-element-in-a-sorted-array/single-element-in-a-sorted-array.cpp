// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid == 0 || mid == (int)nums.size() - 1 ||
                (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]))
                return nums[mid];

            if (nums[mid + 1] == nums[mid] && mid < (int)nums.size()) {
                if (mid % 2 == 0)
                    l = mid + 2;
                else
                    r = mid - 1;
            } else if (nums[mid - 1] == nums[mid] && mid > 0) {
                if (mid % 2 != 0)
                    l = mid + 1;
                else
                    r = mid - 2;
            }
        }
        return -1;
    }
};
// @leet end
