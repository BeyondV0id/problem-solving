#import <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int removeCoveredIntervals(vector<vector<int>> &intervals) {
        int n = intervals.size();
        int cnt = 1;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        // 2 8  3 6

        vector<int> prev = {intervals[0]};

        for (int i = 1; i < n; i++) {
            if (intervals[i][1] <= prev[1]) {
                continue;
            }
            cnt++;
            prev = intervals[i];
        }
        return cnt;
    }
};
