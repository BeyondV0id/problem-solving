/*recursion
class Solution {
private:
    int findMax(vector<int>&nums,int prevIndx,int currIndx){
        if(currIndx == nums.size())return 0;
        if(nums[currIndx]>nums[prevIndx]){
            int x = 1+findMax(nums,currIndx,currIndx+1);
            int y = findMax(nums,prevIndx,currIndx+1);
            return x>y?x:y;

        }
        else{
            return findMax(nums,prevIndx,currIndx+1);
        }

    }
*/
class Solution {
private:
    vector<vector<int>> dp;
    // memoization
    int findMax(vector<int>& nums, int prevIndx, int currIndx) {
        if (currIndx == nums.size())
            return 0;
        if (dp[prevIndx+1][currIndx] != -1)
            return dp[prevIndx+1][currIndx];
        int take = 0;
        if (prevIndx == -1 || nums[currIndx] > nums[prevIndx])
            take = 1 + findMax(nums, currIndx, currIndx + 1);
        int ignore = findMax(nums, prevIndx, currIndx + 1);//ignore
        dp[prevIndx+1][currIndx] = max(take, ignore);
        return dp[prevIndx+1][currIndx];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1, vector<int>(n, -1));
        return findMax(nums, -1, 0);
    }
};
