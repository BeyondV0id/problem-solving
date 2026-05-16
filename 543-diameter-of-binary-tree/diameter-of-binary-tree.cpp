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
    int maxDiameter = 0;
    int getDiameter(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftMaxD = getDiameter(root->left);
        int rightMaxD = getDiameter(root->right);

        int diameter = leftMaxD + rightMaxD;
        maxDiameter = max(maxDiameter, diameter);

        return 1 + max(leftMaxD,rightMaxD);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) { 
        getDiameter(root);
        return maxDiameter;
     }
};