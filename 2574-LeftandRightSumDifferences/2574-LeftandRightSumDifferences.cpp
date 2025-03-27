// Last updated: 3/27/2025, 4:07:50 PM
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>prefix(nums.size()+1,0);
        int psize = prefix.size();
        // 10 4 8 3
        // 0 (0+10) (0+10+4) (0+10+8) (0+10+8+3)

        for(int i=1;i<prefix.size();i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }
        vector<int>result(nums.size());
        for(int i = 0;i<nums.size();i++){
            int leftSum = prefix[i];
            int rightSum = prefix[psize-1] - prefix[i+1];
            result[i] = abs(rightSum-leftSum);
        }
        return result;


        
        
    }
};