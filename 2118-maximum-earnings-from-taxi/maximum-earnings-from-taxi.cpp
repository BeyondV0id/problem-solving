#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<long long> dp;

    int search(int cur, vector<vector<int>>& rides) {
        int l = cur + 1;
        int r = rides.size();

        while (l < r) {
            int m = l + (r - l) / 2;

            if (rides[m][0] >= rides[cur][1])
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    long long backtrack(vector<vector<int>>& rides, int cur) {
        if (cur == rides.size())
            return 0;

        if (dp[cur] != -1)
            return dp[cur];

        long long notPick = backtrack(rides, cur + 1);

        int next = search(cur, rides);

        long long cost =
            rides[cur][1] - rides[cur][0] + rides[cur][2];

        long long pick =
            cost + backtrack(rides, next);

        return dp[cur] = max(pick, notPick);
    }

public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(),
             [](auto& a, auto& b) {
                 return a[0] < b[0];
             });

        int m = rides.size();
        dp.assign(m, -1);

        return backtrack(rides, 0);
    }
};