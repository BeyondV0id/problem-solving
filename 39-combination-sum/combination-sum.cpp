#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> array;

    void backtrack(vector<int>& candidates, int target, int start, int sum) {
        if (sum == target) {
            result.push_back(array);
            return;
        }
        if (sum > target) return;

        for (int i = start; i < candidates.size(); i++) {
            array.push_back(candidates[i]);                     
            backtrack(candidates, target, i, sum + candidates[i]); 
            array.pop_back();                                 
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0, 0);
        return result;
    }
};