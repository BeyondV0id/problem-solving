// Last updated: 3/23/2025, 10:27:52 AM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int minimum = INT_MAX;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m]) {
                minimum = min(nums[l], minimum);
                l = m + 1;
            } else {
                minimum = min(nums[m], minimum);
                r = m - 1;
            }
        }
        return minimum;
    }
};