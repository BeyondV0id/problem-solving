// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        pair<int, int> prev = {intervals[0][0], intervals[0][1]};

        for (int i = 1; i < (int)intervals.size(); i++) {
            int begin = intervals[i][0];
            int end = intervals[i][1];

            if (prev.second >= begin) {
                int longer = max(end, prev.second);
                result.pop_back();
                result.push_back({prev.first, longer});
                prev = {prev.first, longer};
            } else {
                result.push_back(intervals[i]);
                prev = {intervals[i][0], intervals[i][1]};
            }
        }
        return result;
    }
};
// @leet end
