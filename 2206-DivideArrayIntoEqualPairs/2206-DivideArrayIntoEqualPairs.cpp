class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        bool canDivide = true;
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i = 0;i<nums.size();i++){
            if(freq[nums[i]]%2!=0){
                canDivide = false;
            }

        }
        return canDivide;
        
    }
};