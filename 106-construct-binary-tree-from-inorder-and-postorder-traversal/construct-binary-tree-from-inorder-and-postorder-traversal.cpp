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
    unordered_map<int, int> inMap;
    int Indx = 0;
    TreeNode* solve(vector<int>& postorder, int left, int right, int n) {
        if (left > right)
            return nullptr;

        int nodeVal = postorder[n - Indx - 1];
        Indx++;

        int i = inMap[nodeVal];

        TreeNode* tree = new TreeNode(nodeVal);

        tree->right = solve(postorder, i + 1, right, n);
        tree->left = solve(postorder, left, i - 1, n);

        return tree;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int left = 0;
        int right = n - 1;

        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        return solve(postorder, left, right, n);
    }
};