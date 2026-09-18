class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<long,long> seen;
        int n = nums.size();

        seen[0] = 1;
        int res = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int find = sum - k;

            if (seen.count(find)) {
                res += seen[find];
            }
            seen[sum]++;
        }
        return res;
    }
};