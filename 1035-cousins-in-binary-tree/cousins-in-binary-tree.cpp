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
    unordered_map<int, int> getParent;
    unordered_map<int, int> getHeight;

    void helper(TreeNode* root, int height) {
        if (root == nullptr)
            return;

        if (root->left) {
            getParent[root->left->val] = root->val;
            getHeight[root->left->val] = height;
            helper(root->left, height + 1);
        }
        if (root->right) {
            getParent[root->right->val] = root->val;
            getHeight[root->right->val] = height;
            helper(root->right, height + 1);
        }
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root,0);

        if(x == root->val || y == root->val)return false;

        int parentX = getParent[x];
        int parentY = getParent[y];
        int heightX = getHeight[x];
        int heightY = getHeight[y];
 
        if(parentX == parentY)return false;
        if(heightX != heightY)return false;

        return true;

    }
};