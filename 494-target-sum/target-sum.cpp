// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
  int res = 0;
  void backtrack(vector<int>& nums, int target,int index,int curr){
    if(index == (int)nums.size()){
      if(curr == target)
        res += 1;
      return;
    }
    backtrack(nums,target,index+1,curr+nums[index]);
    backtrack(nums,target,index+1,curr-nums[index]);

  }
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    backtrack(nums,target,0,0);
    return res;
    }
};
// @leet end

