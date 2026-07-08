class Solution {
private:
    vector<vector<int>>result;
    vector<int>sub;
    void backtrack(vector<int>&candidates, int index, int curSum, int target){
        int n = candidates.size();

        if(curSum > target){
            return;
        }
        if(curSum == target){
            result.push_back(sub);
            return;
        }

        for(int i = index; i < n; i++){
            sub.push_back(candidates[i]);
            backtrack(candidates,i,curSum+candidates[i],target);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,0,0,target);
        return result;
        
    }
};