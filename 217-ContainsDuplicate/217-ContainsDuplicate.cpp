// Last updated: 3/21/2025, 10:14:36 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        for(auto num:nums){
            if(freq[num]>1)return true;
        }
        return false;
        
    }
};