
// @leet imports start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @leet imports end

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string, int> st;
        int n = word.size();

        for (auto& it : patterns) {
            st[it]++;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string str = word.substr(i, j - i + 1);
                if (st.count(str)) {
                    cnt += st[str];
                    st.erase(str);
                }
            }
        }
        return cnt;
    }
};
