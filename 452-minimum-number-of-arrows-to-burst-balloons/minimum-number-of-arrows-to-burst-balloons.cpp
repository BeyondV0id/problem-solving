class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        if (points.size() == 0)
            return 0;

        int cnt = 1;

        sort(points.begin(), points.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        vector<int> prev = points[0];
        for (int i = 1; i < len; i++) {
            if (points[i][0] > prev[1]) {
                cnt++;
                prev = points[i];
            }
        }
        return cnt;
    }
};