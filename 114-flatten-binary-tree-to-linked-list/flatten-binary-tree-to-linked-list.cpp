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
public:
    void flatten(TreeNode* root) {

        if(!root)return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* leftSide = root->left;
        TreeNode* rightSide = root->right;
        root->right = leftSide;
        root->left = nullptr;

        TreeNode* temp = root;
        while(temp->right != nullptr){
            temp = temp->right;
        }
        temp->right = rightSide;
    }
};