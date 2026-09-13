class Solution {
private:
    vector<vector<int>> dp;

    int search(int cur, vector<vector<int>>& events) {
        int l = cur + 1;
        int r = events.size();

        while (l < r) {
            int m = l + (r - l) / 2;

            if (events[m][0] > events[cur][1])
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    int backtrack(vector<vector<int>>& events, int cur, int k) {
        if (cur == events.size() || k == 0)
            return 0;

        if (dp[cur][k] != -1)
            return dp[cur][k];

        int notPick = backtrack(events, cur + 1, k);

        int next = search(cur, events);

        int pick = events[cur][2] +
                   backtrack(events, next, k - 1);

        return dp[cur][k] = max(pick, notPick);
    }

    // int backtrack(vector<vector<int>>& events, int prev, int cur, int k) {
    //
    //     if (cur == events.size() || k == 0)
    //         return 0;
    //
    //     if (dp[prev + 1][cur][k] != -1)
    //         return dp[prev + 1][cur][k];
    //
    //     int notPick = backtrack(events, prev, cur + 1, k);
    //
    //     int pick = 0;
    //
    //     if (prev == -1 || events[cur][0] > events[prev][1]) {
    //         pick = events[cur][2] +
    //                backtrack(events, cur, cur + 1, k - 1);
    //     }
    //
    //     return dp[prev + 1][cur][k] = max(pick, notPick);
    // }

public:
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end(),
             [](auto& a, auto& b) {
                 return a[0] < b[0];
             });

        int n = events.size();

        dp.assign(n, vector<int>(k + 1, -1));

        return backtrack(events, 0, k);
    }
};