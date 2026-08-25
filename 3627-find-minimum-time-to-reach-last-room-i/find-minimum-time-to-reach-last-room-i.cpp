class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int m = moveTime.size();
        int n = moveTime[0].size();
        int INF = 1e7;

        pq.push({0, {0, 0}});

        vector<pair<int, int>> dirs = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));

        while (!pq.empty()) {
            int time = pq.top().first;

            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (time > minTime[x][y])
                continue;

            if (x == m - 1 && y == n - 1)
                return time;

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newTime = max(moveTime[nx][ny], time) + 1;

                    if (newTime < minTime[nx][ny]) {
                        minTime[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};