#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>>result;
    vector<int>array;
    void backtrack(vector<int>& candidates, int target,int indx,int total){
        if(total == target){
            result.push_back(array);
            return;
        }
        if(indx >= candidates.size() || target < total)
            return;
        const int num = candidates[indx];
        array.push_back(num);
        backtrack(candidates,target,indx,total+num);
        array.pop_back();
        backtrack(candidates,target,indx+1,total);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0,0);
        return result;

        
    }
};
// @lc code=end

