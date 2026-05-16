class Solution {
private:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        maxSum = max(maxSum, left + right + root->val);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};