// @leet imports start
#include <bits/stdc++.h>
#include <deque>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @leet end
