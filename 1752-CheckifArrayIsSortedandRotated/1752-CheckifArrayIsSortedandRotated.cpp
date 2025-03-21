// Last updated: 3/21/2025, 7:12:07 PM
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
        if(nums[nums.size()-1]>nums[0])isRotated++;//if the array is neither  sorted nor rotated 
        // example test case {2 1 3 4}: here 2 cannot be at front if it is rotated as 2<4.
        //(2,|1,3,4|) is sorted but not perfectely rotated
        return isRotated<=1;
    }
};
