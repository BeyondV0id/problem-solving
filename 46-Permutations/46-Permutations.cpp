// Last updated: 4/10/2025, 12:19:44 PM
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
private:
    void backtrack(vector<int>&nums,vector<bool>&visited,
        vector<int>&solve,vector<vector<int>>&result){
        if(solve.size()==nums.size()){
            result.push_back(solve);
            return;
        }

        for(int i = 0;i<nums.size();i++){
            if(visited[i])continue;
            visited[i] = true;
            solve.push_back(nums[i]);
            backtrack(nums,visited,solve,result);


            solve.pop_back();
            visited[i] = false;
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>sol;
        vector<bool>visited(nums.size(),false);
        vector<vector<int>>result;
        backtrack(nums,visited,sol,result);
        return result;

        
    }
};
// @lc code=end

