class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(V, false);
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                cnt++;
            }
        }

        return cnt;
    }
};