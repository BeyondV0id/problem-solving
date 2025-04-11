class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = INT_MIN,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                maxCount = max(cnt,maxCount);
                cnt = 0;
            }
        }
        return max(maxCount,cnt);
        
    }
};