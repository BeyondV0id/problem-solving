class Solution {
private:
    vector<long long> dp;

    int search(int cur, vector<vector<int>>& offers) {
        int l = cur + 1;
        int r = offers.size();

        while (l < r) {
            int m = l + (r - l) / 2;

            if (offers[m][0] > offers[cur][1])
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

    long long backtrack(vector<vector<int>>& offers, int cur) {
        if (cur == offers.size())
            return 0;

        if (dp[cur] != -1)
            return dp[cur];

        long long notPick = backtrack(offers, cur + 1);

        int next = search(cur, offers);

        long long pick = offers[cur][2] + backtrack(offers, next);

        return dp[cur] = max(pick, notPick);
    }

public:
    long long maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(),
             [](auto& a, auto& b) { return a[0] < b[0]; });

        int m = offers.size();
        dp.assign(m, -1);

        return backtrack(offers, 0);
    }
};