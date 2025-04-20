// Last updated: 4/20/2025, 10:31:45 AM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0,r = 0;
        int minWindow = INT_MAX;
        int sum = 0;
        while(r<nums.size()){
             sum +=nums[r];
            while(sum>=target){
                minWindow = min(minWindow,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
            }
            return minWindow==INT_MAX? 0 : minWindow;
         }
};