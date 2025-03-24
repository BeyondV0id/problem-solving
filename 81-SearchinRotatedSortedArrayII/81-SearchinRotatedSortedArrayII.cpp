// Last updated: 3/24/2025, 5:36:25 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] == target ){
                return true;
            }
            if(nums[m] == nums[r] && nums[l] == nums[m]){
                r--;
                l++;
            }
            else if(nums[l]<=nums[m]){
                if(nums[l]<=target &&  target<=nums[m]){
                    r = m-1;
                }
                else{
                    l = m+1;
                }

            }
            else{
                if(nums[m]<=target && target<=nums[r]){
                    l = m+1;
                }
                else{
                    r = m-1;
                }

            }
        }
        return false;
    }
};