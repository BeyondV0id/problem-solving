class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;

        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            ans = min(nums[i] - nums[i+k-1], ans);
        }
        return ans;
    }
};