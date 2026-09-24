#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        int l = 0, r = 0;

        sum = 0;
        int maxLen = INT_MIN;
        while (r < n) {
            sum += nums[r];

            while (l <= r && sum > target) {
                sum -= nums[l++];
            }
            if (sum == target)
                maxLen = max(maxLen, r - l + 1);

            r++;
        }
        if (maxLen == INT_MIN)
            return -1;
        return n - maxLen;
    }
};
