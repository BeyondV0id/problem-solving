// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    int indx(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return ch - 'a';
        }
        return 26 + ch - 'A';
    }

public:
    string minWindow(string s, string t) {
        int n = s.size();
        vector<int> need(52, 0);
        vector<int> window(52, 0);
        int req = 0;
        for (auto ch : t) {
            int idx = indx(ch);
            if (need[idx] == 0)
                req++;
            need[idx]++;
        }
        int curr = 0;
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start = 0;
        while (r < n) {
            int idx = indx(s[r]);
            window[idx]++;
            if (need[idx] > 0 && window[idx] == need[idx]) {
                curr++;
            }
            while (curr == req) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                int leftIdx = indx(s[l]);
                window[leftIdx]--;
                if (need[leftIdx] > 0 && window[leftIdx] < need[leftIdx]) {
                    curr--;
                }
                l++;
            }
            r++;
        }
        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(start, minLen);
    }
};
// @leet end
