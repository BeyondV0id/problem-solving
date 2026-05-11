// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
    void dfs(int node, int ancestor, vector<bool>& visited,
             vector<vector<int>>& adj, vector<vector<int>>& res) {

        visited[node] = true;

        for (auto nei : adj[node]) {
            if (!visited[nei]) {
                res[nei].push_back(ancestor);
                dfs(nei, ancestor, visited, adj, res);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        vector<vector<int>> res(n);

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            dfs(i, i, visited, adj, res);
        }
        return res;
    }
};
// @leet end
