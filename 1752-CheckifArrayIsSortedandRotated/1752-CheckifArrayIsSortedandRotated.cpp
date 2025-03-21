// Last updated: 3/21/2025, 6:26:19 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int j = 0;
        
        for(int i = 1; i < nums.size(); i++) {
            if(j>=nums.size())break;
            if(nums[i] >= nums[j]) {
                j++;
                continue;
            }

            j++;
            while(j < nums.size() - 1) {
                if(nums[j] > nums[j + 1]) {
                    return false;
                }
                j++;
            }

            if(nums[nums.size() - 1] > nums[0]) {
                return false;
            }
        }

        return true;
    }
};
