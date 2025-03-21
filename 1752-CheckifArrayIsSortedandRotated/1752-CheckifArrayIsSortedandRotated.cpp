// Last updated: 3/21/2025, 6:37:19 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int isRotated = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                isRotated++;
                if(isRotated>1) return false;
                
            }
           
        }
        if(nums[nums.size()-1]>nums[0])isRotated++;
        return isRotated<=1;
    }
};
