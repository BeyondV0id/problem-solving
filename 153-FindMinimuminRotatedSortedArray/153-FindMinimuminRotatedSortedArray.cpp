// Last updated: 4/1/2025, 6:19:10 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int minimum = INT_MAX;
        while (l <= r) {
            int m = l + (r - l) / 2;
            minimum = min(nums[m],minimum);
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