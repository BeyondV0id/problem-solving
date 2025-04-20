// Last updated: 4/20/2025, 6:47:42 AM
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int sum = 0;
        seen[0] = -1;
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0)
                sum = sum % k;
            if (seen.count(sum)) {
                int indx = seen[sum];
                if (i - indx >= 2) {
                    found = true;
                    break;
                }
            } else {
                seen[sum] = i;
            }
        }
        return found;
    }
};