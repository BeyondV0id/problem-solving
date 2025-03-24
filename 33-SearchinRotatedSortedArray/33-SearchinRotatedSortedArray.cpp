// Last updated: 3/24/2025, 5:16:41 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left,right;
        left = 0;
        right  = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == target){return mid;}
            else if(nums[left]<= nums[mid]){//left sorted
                if(nums[left]<=target && target<=nums[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }

            }
            else{//right sorted
                if(nums[mid]<=target && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right = mid-1;
                }

            }




        
    }
    return -1;
}
};