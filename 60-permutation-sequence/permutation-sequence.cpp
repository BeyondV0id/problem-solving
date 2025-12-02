// @leet imports start
#include <bits/stdc++.h>
#include <string>
using namespace std;
// @leet imports end

// @leet start
class Solution {
  private:
    vector<int> nums;
    vector<int> fact;
    string ans = "";
    void recursion(int n, int k) {
        if (nums.size() == 0)
            return;
        int indx = k / fact[n - 1];
        int nextPerm = k % fact[n - 1];
        ans += to_string(nums[indx]);
        nums.erase(nums.begin() + indx);
        recursion(nums.size(), nextPerm);
    }
  public:
    string getPermutation(int n, int k) {
        fact.resize(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            nums.push_back(i);
            fact[i] = fact[i - 1] * i;
        }
        nums.push_back(n);
        k--;
        recursion(n, k);
        return ans;
    }
};
// @leet end

