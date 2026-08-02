
class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) parent[px] = py;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for(auto &e : edges) {
            uf.unite(e[0], e[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
};