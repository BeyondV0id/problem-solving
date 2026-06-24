class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //lower_bound:
        int l=0,r=nums.size()-1;
        int ans = nums.size();
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]>=target){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
        
    }
};