class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> seen;

        seen[0] = -1;
        int sum = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            if (k != 0) {
                sum = sum % k;
            }
            if (seen.count(sum)) {
                int indx = seen[sum];
                if (i - indx >= 2)
                    return true;
            } else {
                seen[sum] = i;
            }
        }
        return false;
    }
};