class Solution {

private:
    void shiftLeft(vector<int>& nums, int index) {
        for (int i = index; i < nums.size() - 1; i++) {
            nums[i] = nums[i + 1];
        }
        nums.pop_back();
    }
    void mergeMinPair(vector<int>& nums) {
        //search for min Sum
        int minSum = INT_MAX;
        int minIndx = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (sum < minSum) {
                minIndx = i;
                minSum = sum;
            }
        }
        nums[minIndx] = minSum;
        shiftLeft(nums, minIndx + 1);
    }
    bool isSorted(vector<int>&nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }

public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while (!isSorted(nums)) {
            mergeMinPair(nums);
            cnt++;
        }
        return cnt;
    }
};