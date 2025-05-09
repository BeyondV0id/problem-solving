/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int p = 1;
        int l=0;
        int cnt = 0;
        for(int r=0;r<n;r++){
            p *=nums[r];
            while(p>=k && l<=r){
                p = p/nums[l];
                l++;
            }
            cnt += (r-l+1);
        }
        return cnt;
    }
};
// @lc code=end

