// Last updated: 4/14/2025, 9:11:46 AM
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int maxlen = 1;
        int len = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) 
                len++;
            else {
                maxlen = max(maxlen, len);
                len = 1;
            }
        }
        return max(maxlen, len);
    }
};
