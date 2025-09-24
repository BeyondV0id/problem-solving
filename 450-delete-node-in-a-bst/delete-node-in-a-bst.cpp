// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            } else {
                TreeNode* temp = root->right;
                while(temp->left) temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};
// @leet end
