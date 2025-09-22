// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> arr;
    void find(int k, int target, int sum, int start) {
        if (sum == target && arr.size() == k) {
            res.push_back(arr);
            return;
        }
        if (sum > target || arr.size() > k)
            return;
        for (int i = start; i <= 9; i++) {
            arr.push_back(i);
            find(k, target, sum + i, i + 1);
            arr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        find(k, n, 0, 1);
        return res;
    }
};
// @leet end
