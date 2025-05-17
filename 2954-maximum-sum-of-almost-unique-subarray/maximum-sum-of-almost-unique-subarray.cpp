class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        long long maxxi = 0;
        long long sum = 0;
        unordered_map<int, int> window;
        while (r < n) {
            int num = nums[r];
            window[num]++;
            sum += num;
            r++;
            while (r - l > k) {
                window[nums[l]]--;
                sum -= nums[l];
                if (window[nums[l]] == 0)
                    window.erase(nums[l]);
                l++;
            }

            if (window.size() >= m && r - l  == k)
                maxxi = max(maxxi, sum);
        }
        return maxxi;
    }
};

