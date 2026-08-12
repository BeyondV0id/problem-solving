class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX == parentY)
            return false;

        if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
        } else if (rank[parentX] < rank[parentY]) {
            parent[parentX] = parentY;
        } else {
            parent[parentX] = parentY;
            rank[parentX]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int V = edges.size();
        DSU dsu(V + 1);
        vector<int> ans;

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (dsu.unite(u, v) == false)
                return {u, v};
        }

        return {};
    }
};