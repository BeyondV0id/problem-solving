// @leet imports start
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @leet imports end

// @leet start
class Solution {
  public:
    string addSpaces(string s, vector<int> &spaces) {
        string res = "";
        if (spaces.empty())
            return s;
        int i = 0, j = 0;
        while (i < (int)s.size()) {
            if (j < (int)spaces.size() && i == spaces[j]) {
                res += " ";
                j++;
            }
            res += s[i];
            i++;
        }
        return res;
    }
};
// @leet end


