class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int sum = 0;
        seen[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0)
                sum = sum % k;
            if (seen.count(sum)) {
                int indx = seen[sum];
                if (i - indx >= 2) {
                    return true;
                }
            } else {
                seen[sum] = i;
            }
        }
        return false;
    }
};