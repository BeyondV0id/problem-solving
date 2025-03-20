class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int num:nums){
            freq[num]++;
        }
        //count prefix sum from freq array to find number of smaller elements than current element...
        for(int i=1;i<101;i++){
            freq[i] = freq[i]+freq[i-1];
        }
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            int numsBefore = (nums[i]==0)? 0:freq[nums[i]-1];
            result.push_back(numsBefore);
        }
        return result; 


        
    }
};