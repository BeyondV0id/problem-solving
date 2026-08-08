class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<long long, int> seen;
        int res = 0;

        seen[0] = 1;
        long long sum = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            if (seen.count(sum - k)) {
                res += seen[sum - k];
            }

            seen[sum]++;
        }
        return res;
    }
};