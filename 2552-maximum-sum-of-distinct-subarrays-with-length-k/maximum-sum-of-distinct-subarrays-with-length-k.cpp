class Solution {
private:
    int l = 0;
    int r = 0;
    unordered_set<int> flag;
    long long sum = 0;
    long long maxxi = 0;

public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k)
            return 0;
        for (r = 0; r < n; r++) {
            while (flag.count(nums[r])) {
                flag.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            sum += nums[r];
            flag.insert(nums[r]);
            if (r-l+1 == k) {
                maxxi = max(sum, maxxi);
                flag.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
        }

        return maxxi;
    }
};
// @lc code=end