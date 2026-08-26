#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> children;
    vector<int> treeSize;

    int getSize(int node) {
        int size = 1;

        if (treeSize[node] != -1)
            return treeSize[node];
        for (auto neigh : children[node]) {
            size += getSize(neigh);
        }
        return treeSize[node] = size;
    }

    long long calScore(int node, int N) {
        long long score = 1;

        for (auto child : children[node]) {
            score *= getSize(child);
        }

        int parentSize = N - getSize(node);
        if (parentSize > 0)
            score *= parentSize;
        return score;
    }

public:
    int countHighestScoreNodes(vector<int>& parents) {
        int N = parents.size();
        children.resize(N);
        treeSize.resize(N, -1);

        for (int i = 1; i < N; i++) {
            children[parents[i]].push_back(i);
        }
        int nNodes = 0;
        long long maxScore = INT_MIN;

        for (int i = 0; i < N; i++) {
            long long score = calScore(i, N);
            if (score > maxScore) {
                maxScore = score;
                nNodes = 1;
            } else if (score == maxScore) {
                nNodes++;
            }
        }
        return nNodes;
    }
};
