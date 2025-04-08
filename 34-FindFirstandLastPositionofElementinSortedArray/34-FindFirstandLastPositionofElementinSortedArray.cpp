// Last updated: 4/8/2025, 6:03:01 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1); // Initialize with {-1, -1}
        
        int l = 0, r = nums.size() - 1;
        int firstPos = -1;
        
        // Finding the first occurrence (lower bound)
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) firstPos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        int lastPos = -1;
        l = 0, r = nums.size() - 1;

        // Finding the last occurrence (upper bound) 
        //but different as we return the index of number we use  <=. 

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                if(nums[mid] == target)lastPos = mid;
                l = mid + 1;
            }
        }

        result[0] = firstPos;
        result[1] = lastPos;
        return result;
    }
};
