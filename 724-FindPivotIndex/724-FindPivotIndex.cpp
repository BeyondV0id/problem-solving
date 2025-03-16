class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        int pivot=0;
        int subLeft;
        while(pivot<nums.size()){

            if(pivot == 0){
                subLeft = 0;

            }
            else{
                subLeft = prefix[pivot-1];
            }
            int subRight = prefix[nums.size()-1]-prefix[pivot];

            if(subLeft == subRight)
            {
                return pivot;
            }
            pivot++;
        }
        return -1;  
    }
};