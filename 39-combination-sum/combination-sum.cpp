class Solution {
private:
    vector<vector<int>> sol;
    vector<int> subsol;
    void backtrack(vector<int>& candidates, int target, int start) {
        if (target < 0)
            return;
        if (target == 0) {
            sol.push_back(subsol);
        }

        for (int i = start; i < candidates.size(); i++) {
            subsol.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i],i);
            subsol.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return sol;
    }
};