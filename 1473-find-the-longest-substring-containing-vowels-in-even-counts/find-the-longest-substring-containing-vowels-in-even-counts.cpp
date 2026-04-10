// @leet imports start
#include <bits/stdc++.h>
#include <tuple>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        map<tuple<int, int, int, int, int>, int> mp;
        mp[{0, 0, 0, 0, 0}] = -1;
        int maxLen = 0;
        for (int cur = 0; cur < (int)s.size(); cur++) {
            char c = s[cur];
            if (c == 'a')
                a ^= 1;
            else if (c == 'e')
                e ^= 1;
            else if (c == 'i')
                i ^= 1;
            else if (c == 'o')
                o ^= 1;
            else if (c == 'u')
                u ^= 1;
            auto current = make_tuple(a, e, i, o, u);
            if (mp.count(current)) {
                int indx = mp[current];
                maxLen = max(maxLen, cur - indx);
            } else {
                mp[current] = cur;
            }
        }
        return maxLen;
    }
};
// @leet end

