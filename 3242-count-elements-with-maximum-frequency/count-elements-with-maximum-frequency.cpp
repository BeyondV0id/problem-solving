// @leet imports start
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @leet imports end

// @leet start
class Solution {
  public:
    int maxFrequencyElements(vector<int> &nums) {
        unordered_map<int, int> freq;
        int maxFreq = INT_MIN;
        int res = 0;
        for (auto &it : nums) {
            freq[it]++;
            if (freq[it] > maxFreq)
                maxFreq = freq[it];
        }
        for (auto &it : nums) {
            if (freq[it] == maxFreq)
                res++;
        }
        return res;
    }
};
// @leet end

