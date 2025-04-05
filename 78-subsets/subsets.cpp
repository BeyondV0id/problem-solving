class Solution {
private:
    void backtrack(vector<int>& nums, int index, vector<int>& current,vector<vector<int>>& result) {
        result.push_back(current);//push current to result
        for (int i = index; i < nums.size(); i++) {
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
    vector<vector<int>> subsets(vector<int>& nums) { return subSet(nums); }
};