class Solution {
  private:
    vector<int> levelSum;
    void dfs(TreeNode *root, int depth) {
        if (root == nullptr)
            return;

        if (depth == (int)levelSum.size())
            levelSum.push_back(0);

        levelSum[depth] += root->val;

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    void dfs2(TreeNode *root, int depth) {
        if (!root)
            return;

        int siblingsSum = 0;
        if (root->left) {
            siblingsSum += root->left->val;
        }
        if (root->right) {
            siblingsSum += root->right->val;
        }

        if (root->left)
            root->left->val = levelSum[depth + 1] - siblingsSum;
        if (root->right)
            root->right->val = levelSum[depth + 1] - siblingsSum;

        dfs2(root->left, depth + 1);
        dfs2(root->right, depth + 1);
    }

  public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        dfs(root, 0);
        root->val = 0;
        dfs2(root, 0);
        return root;
    }

};
