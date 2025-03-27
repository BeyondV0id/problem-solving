// Last updated: 3/27/2025, 3:34:12 PM
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int close = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int absValue = abs(nums[i]);
            if (abs(nums[i]) < abs(close) ||
                (absValue == abs(close) && nums[i] > close)) {
                close = nums[i];
            }
        }
        return close;
    }

};