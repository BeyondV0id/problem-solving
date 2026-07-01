class Solution {

    int lowerBound(vector<int>&nums,int target){
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;


        while(l <= r){
            int mid = l + (r-l)/2;

            //go left

            if(target <= nums[mid]){
                if(target == nums[mid])ans = mid;
                r = mid-1;
            }
            else if(target > nums[mid]){
                l = mid + 1;
            }
        }
        return ans;
    }
        int upperBound(vector<int>&nums,int target){
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;


        while(l <= r){
            int mid = l + (r-l)/2;

            //go right
            if(target >= nums[mid]){
                if(target == nums[mid])ans = mid;
                l = mid + 1;
            }
            else if(target < nums[mid]){
                r = mid - 1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int lb = lowerBound(nums,target);
        int ub = upperBound(nums,target);
        res.push_back(lb);
        res.push_back(ub);
        return res;
    }
};