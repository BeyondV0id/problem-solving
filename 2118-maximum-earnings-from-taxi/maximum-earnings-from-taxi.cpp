class Solution {
private:
    vector<long long> dp;
    int search(vector<vector<int>>& rides, int index) {

        int l = index + 1, r = rides.size();

        while (l < r) {
            int m = (r - l) / 2 + l;

            if (rides[m][0] > rides[index][1]) {
                r = m;
            } else if (rides[m][0] == rides[index][1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    long long backtrack(int n, vector<vector<int>>& rides, int index) {
        if (index >= rides.size()) {
            return 0;
        }
        if (dp[index] != -1)
            return dp[index];

        long long pick;

        int nextIndx = search(rides, index);

        long long earn = rides[index][2] + rides[index][1] - rides[index][0];

        pick = earn + backtrack(n, rides, nextIndx);

        long long notPick = backtrack(n, rides, index + 1);

        return dp[index] = max(pick, notPick);
    }

public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(),
             [](auto& a, auto& b) { return a[0] < b[0]; });

        int m = rides.size();
        dp.assign(m, -1);
        return backtrack(n, rides, 0);
    }
};