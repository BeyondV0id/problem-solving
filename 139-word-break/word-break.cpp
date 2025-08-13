#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<int> memo;
    bool backtrack(string& s, unordered_set<string>& check, int stage) {
        if (stage == (int)s.length()) return true;
        if (memo[stage] != -1) return memo[stage];
        for (int i = stage; i < (int)s.size(); i++) {
            string str = s.substr(stage, i - stage + 1);
            if (check.count(str) && backtrack(s, check, i + 1))
                return memo[stage] = 1;
        }
        return memo[stage] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> check(wordDict.begin(), wordDict.end());
        memo.assign(s.size(), -1);
        return backtrack(s, check, 0);
    }
};
