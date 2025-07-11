class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(TreeNode* root, int targetSum) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL &&
            targetSum == root->val) {
            result.push_back(path);
            path.pop_back();
            return;
        }

        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
};
// @lc code=end
