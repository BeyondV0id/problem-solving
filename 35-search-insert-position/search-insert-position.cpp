class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // lower_bound:
        int l = 0, r = nums.size();
        int ans = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};