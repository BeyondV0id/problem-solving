#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
private:
    vector<vector<int>> dp;
    bool isPred(string& a, string& b) {
        int m = a.size();
        int n = b.size();

        if (b.size() != a.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == m;
    }
    int backtrack(vector<string>& words, int cur, int prev) {
        if (cur == (int)words.size())
            return 0;

        if (dp[cur][prev + 1] != -1)
            return dp[cur][prev + 1];
        int notPick = backtrack(words, cur + 1, prev);

        int pick = 0;
        if (prev == -1 || isPred(words[prev], words[cur])) {
            pick = 1 + backtrack(words, cur + 1, cur);
        }

        return dp[cur][prev + 1] = max(pick, notPick);
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });

        int n = words.size();

        dp.assign(n, vector<int>(n + 1, -1));
        return backtrack(words, 0, -1);
    }
};
