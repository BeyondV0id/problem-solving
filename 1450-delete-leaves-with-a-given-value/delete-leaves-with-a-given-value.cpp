// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start

class Solution {
private:
    TreeNode* dfs(TreeNode* root, int target) {
        if (!root)
            return nullptr;
        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);
        if (!root->left && !root->right && target == root->val)
            return nullptr;
        return root;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* newRoot = dfs(root, target);
        return newRoot;
    }
};
// @leet end


