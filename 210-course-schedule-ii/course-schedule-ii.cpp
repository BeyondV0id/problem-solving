#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, stack<int>& stk, vector<vector<int>>& adj,
             vector<bool>& visited, vector<bool>& pathVis) {

        visited[node] = true;
        pathVis[node] = true;

        for (auto &it : adj[node]) {

            if (!visited[it]) {
                if (dfs(it, stk, adj, visited, pathVis))
                    return true;
            }
            else if (pathVis[it]) {
                return true;   // cycle detected
            }
        }

        pathVis[node] = false;
        stk.push(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        stack<int> stk;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, stk, adj, visited, pathVis))
                    return {};   // cycle found
            }
        }

        vector<int> res;

        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};

