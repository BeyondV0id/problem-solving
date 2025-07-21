/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
private:
    unordered_map<int, int> seen;
    int preCnt = 0;
    int cnt = 0;

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        seen[0] = 1;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num % 2 != 0)
                preCnt++;
            if (seen.count(preCnt - k)) {
                cnt += seen[preCnt - k];
            }
            seen[preCnt]++;
        }
        return cnt;
    }
};
// @lc code=end
