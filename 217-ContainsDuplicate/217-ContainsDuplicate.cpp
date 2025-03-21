// Last updated: 3/21/2025, 10:19:14 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool>seen;
        for(int num:nums){
            if(seen[num])return true;
            seen[num] = true;
        }
        return false;

    
        
    }
};