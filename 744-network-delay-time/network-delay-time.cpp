class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            graph[u].push_back({v, weight});
        }

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;

            pq.pop();

            for (auto neigh : graph[node]) {
                int adjNode = neigh.first;
                int edgeW = neigh.second;

                if (dis + edgeW < dist[adjNode]) {
                    dist[adjNode] = dis + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = INT_MIN;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }
        return ans;
    }
};