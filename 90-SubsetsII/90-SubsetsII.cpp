// Last updated: 4/5/2025, 11:48:31 AM
//vector<vector<int>> subsetsWithDup(vector<int>& nums) {
class Solution {
private:
    void backtrack(vector<int>& nums, int index, vector<int>& current,vector<vector<int>>& result) {
        result.push_back(current);//push current to result
        for (int i = index; i < nums.size(); i++) {
            if(i!=index && nums[i] == nums[i-1])continue;
            current.push_back(nums[i]);
            backtrack(nums,i+1,current,result);
            current.pop_back();

        }
    }
    vector<vector<int>> subSet(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        return subSet(nums); }
};      
    