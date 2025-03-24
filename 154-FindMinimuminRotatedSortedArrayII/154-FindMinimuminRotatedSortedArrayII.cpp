// Last updated: 3/24/2025, 5:59:39 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int minimum = INT_MAX;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            minimum = min(minimum, nums[m]);

            // First check for duplicate case
            if (nums[m] == nums[r]) { 
                r--; // Remove duplicate
            } 
            else if (nums[m] > nums[r]) { 
                // Min must be on the right side
                l = m + 1;
            } 
            else { 
                // Min is on the left side (including mid)
                r = m;
            }
        }
        return minimum;
    }
};
