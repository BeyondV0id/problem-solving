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
    int ans = 0;
    pair<int, int> calc(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto left = calc(root->left);
        auto right = calc(root->right);

        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;

        if (sum / cnt == root->val)
            ans++;

        return {sum, cnt};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        calc(root);
        return ans;
    }
};