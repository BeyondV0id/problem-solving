#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {

        if (parent[x] == x)
            return x;

        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

        int rankX = rank[rootX];
        int rankY = rank[rootY];

        if (rankX > rankY) {
            parent[rootY] = rootX;
        } else if (rankY > rankX) {
            parent[rootX] = rootY;
        } else {
            rank[rootX]++;
            parent[rootY] = rootX;
        }

        return true;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int N = accounts.size();
        parent.resize(N);
        rank.resize(N, 0);

        unordered_map<string, int> getParent;

        vector<vector<string>> result;

        for (int i = 0; i < N; i++)
            parent[i] = i;

        for (int i = 0; i < N; i++) {
            for (int j = 1; j < (int)accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (!getParent.count(mail)) {
                    getParent[mail] = i;
                } else {
                    unite(getParent[mail], i);
                }
            }
        }

        vector<vector<string>> mails(N);
        for (auto it : getParent) {
            string mail = it.first;
            int parent = find(it.second);
            mails[parent].push_back(mail);
        }

        for (int i = 0; i < N; i++) {
            if (mails[i].empty())
                continue;
            string name = accounts[i][0];
            vector<string> account;
            account.push_back(name);
            sort(mails[i].begin(), mails[i].end());
            for (auto& mail : mails[i])
                account.push_back(mail);

            result.push_back(account);
        }
        return result;
    }
};