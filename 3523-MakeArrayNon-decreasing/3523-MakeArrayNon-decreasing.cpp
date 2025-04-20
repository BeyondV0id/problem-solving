// Last updated: 4/20/2025, 1:47:50 PM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        //monotonic increasinng stack
        int n = nums.size();
        int cnt = 1;
        int prev = nums[0];

        for (int i=1;i<n;i++) {
            if(nums[i]>=prev){
                cnt++;
                prev = nums[i];
                
            }
        }

       return cnt;
    }
};
