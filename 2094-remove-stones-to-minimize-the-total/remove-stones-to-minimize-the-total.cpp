
// @leet imports start
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
using namespace std;
// @leet imports end
//
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(piles[i]);
        }

        while (!pq.empty() && k > 0) {
            int top = pq.top();
            pq.pop();
            k--;
            pq.push(top - floor(top / 2));
        }
        int cnt = 0;
        while (!pq.empty()) {
            cnt += pq.top();
            pq.pop();
        }
        return cnt;
    }
};
