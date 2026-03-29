// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  int res = 0;
  pair<int,int>dfs(TreeNode* root){
    if(root == nullptr)
      return {0,0};

    auto [lsize,lcoins] = dfs(root->left);
    auto [rsize,rcoins] = dfs(root->right);

    int totalSize = lsize + rsize + 1;
    int totalCoins = lcoins + rcoins + root->val;

    res += abs(totalCoins - totalSize);

    return {totalSize,totalCoins};
  }
public:
    int distributeCoins(TreeNode* root) {
      dfs(root);
      return res;
      
    }
};
// @leet end

