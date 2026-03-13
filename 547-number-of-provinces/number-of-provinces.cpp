class Solution {
  private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

    int find(int x, vector<int> &parent) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool isConnected(int x, int y, vector<int> &parent) {
        return (find(x, parent) == find(y, parent));
    }

    bool united(int v1, int v2, vector<int> &parent, vector<int> &rank) {
        int parent1 = find(v1, parent);
        int parent2 = find(v2, parent);

        if (parent1 == parent2) return false;

        int rank1 = rank[parent1];
        int rank2 = rank[parent2];

        if (rank1 < rank2) {
            parent[parent1] = parent2;
        } else if (rank1 > rank2) {
            parent[parent2] = parent1;
        } else {
            parent[parent2] = parent1;
            rank[parent1]++;
        }

        return true;
    }

  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int V = isConnected.size();

        vector<int> parent(V);
        vector<int> rank(V, 1);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int cnt = 0;
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && isConnected[i][j] != 0) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                cnt++;
            }
        }

        return cnt;
    }
};