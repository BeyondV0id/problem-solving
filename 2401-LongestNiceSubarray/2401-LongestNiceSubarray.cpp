class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;

        for (int i = 0; i < n; i++) {
            int bitmask = 0;
            for (int j = i; j < n; j++) {
                if ((bitmask & nums[j]) != 0) break;
                bitmask |= nums[j];
                maxLength = max(maxLength, j - i + 1);
            }
        }

        return maxLength;
    }
};
