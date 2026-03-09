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
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int res = INT_MIN;

        while (!q.empty()) {
            int n = q.size();
            long long firstIndx = q.front().second;
            long long lastIndx = q.back().second;
            int width = lastIndx - firstIndx + 1;
            res = max(res, width);
            for (int i = 0; i < n; i++) {
                auto [node, indx] = q.front();
                q.pop();
                indx -= firstIndx;
                if (node->left) {
                    q.push({node->left, 2 * indx + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * indx + 2});
                }
            }
        }

        return res;
    }
};