// Last updated: 4/19/2025, 9:01:14 AM
class Solution {
private:
    int findpos(vector<int>& nums, int target, int l, int r, bool isLower) {
        int ans = r + 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((isLower && nums[mid] >= target) || (!isLower && nums[mid] > target)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int lowVal = lower - nums[i];
            int highVal = upper - nums[i];
            //[0,1,4,4,5,7]
            int lb = findpos(nums, lowVal, i + 1, n - 1, true);   // lower bound
            int ub = findpos(nums, highVal, i + 1, n - 1, false);  // upper bound

            cnt += ub - lb;
        }

        return cnt;
    }
};
