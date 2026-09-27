class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        vector<long long> F(n);

        for (int i = 0; i < n; i++) {
            F[0] += i * nums[i];
        }

        long long maxxi = F[0];

        for (int i = 1; i < n; i++) {
            F[i] = F[i - 1] + sum - n * nums[n - i];

            maxxi = max(maxxi, F[i]);
        }

        return maxxi;
    }
};