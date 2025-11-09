#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<int, vector<int>> indxMap;
    int res = INT_MAX;

public:
    int minimumDistance(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            indxMap[nums[i]].push_back(i);
        }
        for (auto& [num, indxList] : indxMap) {
            if (indxList.size() < 3)
                continue;
            for (int i = 0; i < (int)indxList.size()-2; i++) {
                int i1 = indxList[i];
                int i3 = indxList[i + 2];
                res = min(res, abs(2 * (i3 - i1)));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
