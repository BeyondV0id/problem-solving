// @leet imports start
#include <bits/stdc++.h>
#include <queue>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;

        for (auto ch : s) {
            freq[ch]++;
        }
        priority_queue<pair<char, int>> pq;
        string res = "";

        for (auto [ch, cnt] : freq) {
            pq.push({ch, cnt});
        }

        while (!pq.empty()) {
            auto [ch, cnt] = pq.top();
            pq.pop();

            if (cnt > repeatLimit) {
                int temp = repeatLimit;
                while (temp) {
                    res.push_back(ch);
                    temp--;
                }
                cnt -= repeatLimit;
            } else {
                int temp = cnt;
                while (temp) {
                    res.push_back(ch);
                    temp--;
                }
                cnt = 0;
            }
            if (cnt > 0) {
                if (pq.empty()) {
                    break;
                }

                auto [ch2, cnt2] = pq.top();
                pq.pop();
                res.push_back(ch2);
                cnt2--;
                if (cnt2 > 0) {
                    pq.push({ch2, cnt2});
                }
                pq.push({ch, cnt});
            }
        }
        return res;
    }
};
// @leet end
