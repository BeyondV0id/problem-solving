// Last updated: 4/8/2025, 4:58:12 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        int i;
        for( i=nums.size()-1;i>=0;i--){
            if(mp[nums[i]]>0)break;
            mp[nums[i]]++;
        }
        int a=ceil((i+1)/3.0);
        return a;
    }
};