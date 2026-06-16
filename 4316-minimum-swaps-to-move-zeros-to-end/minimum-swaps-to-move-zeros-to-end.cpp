// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end
class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int swaps = 0;
        while (l < r) {
            while ( l < r && nums[l] != 0)
                l++;
            while (l < r && nums[r] == 0) {
                r--;
            }
            if (l < r) {
                swap(nums, l, r);
                l++;
                r--;
                swaps++;
            }
        }
        return swaps;
    }
};
