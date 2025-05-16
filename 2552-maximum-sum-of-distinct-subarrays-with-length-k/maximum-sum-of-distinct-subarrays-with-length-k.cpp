class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> flag;
        long long sum = 0;
        long long maxxi = 0;
        int l = 0;
        
        for (int r = 0; r < n; r++) {
            if (!flag.count(nums[r])) {
                sum += nums[r];
                flag.insert(nums[r]);
                
                if (r - l + 1 == k) {
                    maxxi = max(maxxi, sum);
                    sum -= nums[l];
                    flag.erase(nums[l]);
                    l++;
                }
            } else {
                while (nums[l] != nums[r]) {
                    sum -= nums[l];
                    flag.erase(nums[l]);
                    l++;
                }
                l++;
            }
        }
        
        return maxxi;
    }
};