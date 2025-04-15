// Last updated: 4/15/2025, 9:31:13 PM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> indxMap;
        indxMap[0] = -1;
        int diff = 0;
        indxMap[diff] = -1;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                diff++;
            else
                diff--;
            if (indxMap.count(diff))
                maxLen = max(maxLen, i - indxMap[diff]);
            else
                indxMap[diff] = i;
        }
        return maxLen;
    }
};