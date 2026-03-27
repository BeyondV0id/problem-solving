class Solution {
public:
    vector<vector<int>> result;

    void dfs(int node, vector<int>& path, vector<vector<int>>& graph) {
        path.push_back(node);

        if (node == graph.size() - 1) {
            result.push_back(path);
        } else {
            for (int next : graph[node]) {
                dfs(next, path, graph);
            }
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0, path, graph);
        return result;
    }
};