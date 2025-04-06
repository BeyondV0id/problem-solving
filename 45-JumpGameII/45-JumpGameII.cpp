// Last updated: 4/6/2025, 6:55:14 PM
class Solution {
private:
    /*int findjump(int indx,int jumps,vector<int>& nums){
        if(indx>=nums.size()-1)return jumps;
        if(nums[indx] == 0)return INT_MAX;

        for(int i = 1;i<=nums[indx];i++){
            mini = min(mini,findjump(indx+i,jumps+1,nums))

        }
        return mini;
        }*/

public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j<n)
                    dp[i+j] = min(dp[i]+1,dp[j+i]);
            }
        }
        return dp[n-1];




        
    }
};