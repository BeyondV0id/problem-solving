// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
  public:
    int maxLevelSum(TreeNode *root) {
      queue<TreeNode*>q;
      int curlvl = 1;
      int reslvl = 1;
      int maxSum = INT_MIN;
      q.push(root);
      while(!q.empty()){
        int sum = 0;
        int n = q.size();
        for(int i = 0;i < n;i++){
          TreeNode* node = q.front();
          q.pop();
          sum += node->val;
          if(node->left)q.push(node->left);
          if(node->right)q.push(node->right);
        }
        if(sum > maxSum){
          reslvl = curlvl;
          maxSum = sum;
        }
        curlvl++;
      }
      return reslvl;
    }
};
// @leet end


