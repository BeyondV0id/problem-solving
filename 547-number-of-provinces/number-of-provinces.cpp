#include <bits/stdc++.h>
using namespace std;

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

        parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {

        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false;

        int rankX = rank[rootX];
        int rankY = rank[rootY];

        if (rankX > rankY)
            parent[rootY] = rootX;

        else if (rankX < rankY)
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
    bool isConnected(int x, int y) {
        if (find(x) == find(y))
            return true;
        return false;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DSU dsu(V);
        vector<vector<int>> edges(V);
        int components = V;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && isConnected[i][j] != 0) {
                    if (dsu.unite(i, j))
                        components--;
                }
            }
        }
        return components;
    }
};
