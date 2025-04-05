/*
case 1:
 { },
 { 1 },
 { 1 2 },
 { 1 2 3 },
 { 1 3 },
 { 2 },
 { 2 3 },
 { 3 },

case 2:
 { },
 { 1 },
 { 1 2 },
 { 1 2 2 },
 { 2 },
 { 2 2 },

if we replace 3 to 2
1 2 2 is fine

but 1 2 and 1 2 is duplicate...

at 1 2 3 each step index == i

but at      {1 , 2}        and       {1 , 3}
    index = 0,i = 1          index = 0,i = 2


skip if i not eqaul to index and nums[i] == nums[i-1]//sorted


 { },
 { 1 },
 { 1 2 },
 { 1 2 2 },
 { 2 },
 { 2 2 },
 */

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
    