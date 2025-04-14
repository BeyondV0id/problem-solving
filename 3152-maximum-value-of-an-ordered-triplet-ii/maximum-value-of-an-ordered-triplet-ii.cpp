/*
 * @lc app=leetcode id=2874 lang=cpp
 *
 * [2874] Maximum Value of an Ordered Triplet II
 */

// @lc code=start
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       int n = nums.size();
       long long  maxNum = nums[0];
       long long  maxDiff = LLONG_MIN;
       long long res = 0;
       for(int j = 1;j<n-1;j++){
        maxDiff = max(maxDiff,maxNum-(long long)nums[j]);
        res = max(res,maxDiff*nums[j+1]);
        maxNum = max(maxNum,(long long)nums[j]);
       }
       return res>0?res:0;

        
    }
};
// @lc code=end

