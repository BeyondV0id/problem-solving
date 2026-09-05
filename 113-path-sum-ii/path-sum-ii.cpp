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
    vector<vector<int>> res;

    void dfs(TreeNode* root, int targetSum, vector<int> path) {
        if (!root)
            return;

        path.push_back(root->val);

        if (!root->left && !root->right) {
            if (targetSum == root->val) {
                res.push_back(path);
            }

            return;
        }

        dfs(root->left, targetSum - root->val, path);
        dfs(root->right, targetSum - root->val, path);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return res;
    }
};