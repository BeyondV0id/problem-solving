class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        unordered_map<int, int> seen;
        seen[0] = 1;

        int preSum = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            preSum += nums[i];

            if (seen.count(preSum - goal))
                res += seen[preSum - goal];

            seen[preSum]++;
        }
        return res;
    }
};