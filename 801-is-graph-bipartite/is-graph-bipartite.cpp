class Solution {
private:
    bool dfs(vector<vector<int>>& graph, int node, int col,
             vector<int>& color) {

        color[node] = col;

        for (auto neigh : graph[node]) {
            if (color[neigh] == -1) {
                if (dfs(graph, neigh, !col, color) == false)
                    return false;
            } else {
                if (color[node] == color[neigh])
                    return false;
            }
        }
        return true;
    }
    bool bfs(vector<vector<int>>& graph, int node, vector<int>& color) {

        queue<int> q;

        q.push(node);

        color[node] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto neigh : graph[node]) {
                if (color[neigh] == -1) {
                    q.push(neigh);
                    color[neigh] = !color[node];
                } else if (color[node] == color[neigh])
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(graph, i,0, color) == false)
                    return false;
            }
        }
        return true;
    }
};