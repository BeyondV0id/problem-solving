class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> presum;
        int sum = 0;
        int cnt = 0;
        int n = nums.size();
        presum[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = sum % k;
            if (mod < 0) {
                mod += k;
            }

            if (presum.count(mod)) {
                cnt += presum[mod];
            }
            presum[mod]++;
        }

        return cnt;
    }
};
