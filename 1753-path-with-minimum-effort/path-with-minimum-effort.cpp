class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();
            if (x == m - 1 && y == n - 1)
                return d;

            for (auto [dx, dy] : dirs) {
                int nx = dx + x;
                int ny = dy + y;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newEffort =
                        max(abs(heights[nx][ny] - heights[x][y]), d);

                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};