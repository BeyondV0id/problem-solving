// Last updated: 4/20/2025, 12:09:01 PM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && nums[i]>nums[j]) j++;
            ans-=(j-i-1);
            i=j;
        }
        return ans;
    }
};