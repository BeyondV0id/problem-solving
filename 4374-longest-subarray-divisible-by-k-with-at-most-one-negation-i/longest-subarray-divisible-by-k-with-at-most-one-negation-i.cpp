class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> mp;

            long long sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                int neg = ((2LL * nums[j]) % k + k) % k;
                mp.insert(neg);

                long long rem = ((sum % k) + k) % k;

                if (rem == 0 || mp.count(rem)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};