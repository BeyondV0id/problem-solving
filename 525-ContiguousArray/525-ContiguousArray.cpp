// Last updated: 4/15/2025, 3:17:23 PM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> indxMap;
        indxMap[0] = -1;
        int diff  = 0;
        indxMap[diff] = -1;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                diff++;
            else
                diff--;
            if (indxMap.count(diff))
                maxLen = max(maxLen, i - indxMap[diff]);
            if (indxMap.find(diff) == indxMap.end()) {//the diff is not in the map....
                indxMap[diff] = i;
            }
        }
        return maxLen;
    }
};