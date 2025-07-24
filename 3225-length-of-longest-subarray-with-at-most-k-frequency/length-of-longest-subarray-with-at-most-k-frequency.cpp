/*
 * @lc app=leetcode id=2958 lang=cpp
 *
 * [2958] Length of Longest Subarray With at Most K Frequency
 */

// @lc code=start
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    unordered_map<int,int>freq;
    int maxlen = 0;
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0;
        while(r<nums.size()){
            int num = nums[r++];
            freq[num]++;
            while(freq[num]>k){
                freq[nums[l]]--;
                l++;
            }
            maxlen = max(r-l,maxlen);
        }
        return maxlen;
    }
};
// @lc code=end

