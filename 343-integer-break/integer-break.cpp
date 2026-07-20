#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int backtrack(int num,vector<int>&dp) {
        if (num == 1)
            return 1;

        if(dp[num]!=-1)return dp[num];
        int ans = 0;

        for (int i = 1; i < num; i++) {
            int left = max(i, backtrack(i,dp));
            int right = max(num - i, backtrack(num - i,dp));

            ans = max(ans, left * right);
        }

        return dp[num] = ans;
    }

public:
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        if (n == 2) return 1;
        return backtrack(n,dp);
    }
};