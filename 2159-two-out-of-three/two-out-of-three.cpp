// @leet imports start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<int> res;

public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                              vector<int>& nums3) {
        unordered_map<int, int> freq;
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> set3(nums3.begin(), nums3.end());
        for (int it : set1)
            freq[it]++;
        for (int it : set2)
            freq[it]++;
        for (int it : set3)
            freq[it]++;

        for (auto& it : freq) {
            if (it.second >= 2)
                res.push_back(it.first);
        }
        return res;
    }
};
// @leet end
