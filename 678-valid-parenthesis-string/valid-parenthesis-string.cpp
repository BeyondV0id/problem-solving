class Solution {
private:
    vector<vector<int>> dp;
    bool solve(string s, int i, int open) {
        if (open < 0)
            return 0;

        if (i == s.size()) {
            return open == 0;
        }
        if (dp[i][open] != -1) {
            return dp[i][open];
        }

        bool ans = false;
        if (s[i] == '(') {
            ans = solve(s, i + 1, open + 1);

        } else if (s[i] == ')') {
            ans = solve(s,i + 1, open - 1);

        } else {
            bool a = solve(s,i + 1, open - 1);
            bool b = solve(s,i + 1, open + 1);
            bool c = solve(s,i + 1, open);

            ans = a | b | c;
        }
        return dp[i][open] = ans;
    }

public:
    bool checkValidString(string s) {
        int n = s.size();

        dp.assign(n, vector<int>(n + 1, -1));
        return solve(s, 0, 0);
    }
};