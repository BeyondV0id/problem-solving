#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int ones = 0;
        int l = 0, r = 0;
        string res;

        while (r < n) {
            int num = s[r++] - '0';
            if (num == 1)
                ones++;

            while (ones > k) {
                if (s[l] - '0' == 1) {
                    ones--;
                }
                l++;
            }

            if (ones == k) {
                while (l <= r && s[l] == '0') {
                    l++;
                }
                string sub = s.substr(l, r - l);
                if (res == "")
                    res = sub;
                else {
                    int rLen = res.size();
                    int sLen = sub.size();
                    if (sLen < rLen) {
                        res = sub;
                    } else if (sLen == rLen) {
                        res = min(sub, res);
                    }
                }
            }
        }
        return res;
    }
};
