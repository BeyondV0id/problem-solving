class Solution {
private:
    void dfs(vector<vector<int>>& graph, int source, vector<int>& vis) {

        vis[source] = 1;

        for (auto neigh : graph[source]) {
            if (vis[neigh] == -1)
                dfs(graph, neigh, vis);
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        vector<vector<int>> graph(n);
        vector<int> vis(n, -1);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        dfs(graph, source, vis);

        return vis[destination] == 1;
    }
};