class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size();
        sort(points.begin(), points.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int prev = points[0][0];
        int cnt = 1;

        for(int i = 1;i < n; i++){
            if(points[i][0] > w + prev){
                cnt++;
                prev = points[i][0];
            }
        }
        return cnt;
    }
};