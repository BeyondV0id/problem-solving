/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

private:
    bool dfs(TreeNode* root, long long max, long long min) {

        if (!root)
            return true;

        if (root->val >= max || root->val <= min)
            return false;

        if (dfs(root->left, root->val, min) == false)
            return false;

        if (dfs(root->right, max, root->val) == false)
            return false;

        return true;
    }

public:
    bool isValidBST(TreeNode* root) { return dfs(root, LLONG_MAX, LLONG_MIN); }
};