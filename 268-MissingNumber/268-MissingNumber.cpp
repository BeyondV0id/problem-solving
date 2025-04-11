// Last updated: 4/11/2025, 5:03:31 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0,i;
        int realSum = 0;
        for(i=0;i<nums.size();i++){
            sum +=i;
            realSum +=nums[i];

        }
        sum +=i;
        return sum-realSum;

        
    }
};