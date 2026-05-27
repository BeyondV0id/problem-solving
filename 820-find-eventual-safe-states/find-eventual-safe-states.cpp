// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> g(n);
        vector<int> outDegree(n, 0);

        for (int u = 0; u < n; u++) {
            int outGoings = graph[u].size();
            outDegree[u] = outGoings;
            for (int v : graph[u]) {
                g[v].push_back(u);
            }
        }
        queue<int> q;
        for (int u = 0; u < (int)outDegree.size(); u++) {
            if (outDegree[u] == 0) {
                q.push(u);
            }
        }
        vector<int> res;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto neigh : g[node]) {
                outDegree[neigh]--;
                if (outDegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
