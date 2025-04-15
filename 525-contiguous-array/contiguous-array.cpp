class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> indxMap;
        indxMap[0] = -1;
        int cnt1 = 0, cnt2 = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                cnt1++;
            else
                cnt2++;
            int diff = cnt2 - cnt1;

            if (indxMap.count(diff))
                maxLen = max(maxLen, i - indxMap[diff]);
            if (indxMap.find(diff) == indxMap.end()) {//the diff is not in the map....
                indxMap[diff] = i;
            }
        }
        return maxLen;
    }
};