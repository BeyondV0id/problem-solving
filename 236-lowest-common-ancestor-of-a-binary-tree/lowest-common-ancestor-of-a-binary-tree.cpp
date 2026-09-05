/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, int> first;
    vector<int> depth;
    vector<TreeNode*> eulers;

    void dfs(TreeNode* root, int d) {
        if (!root)
            return;

        if (!first.count(root)) {
            first[root] = eulers.size();
        }

        depth.push_back(d);
        eulers.push_back(root);

        if (root->left) {
            dfs(root->left,d+1);
            eulers.push_back(root);
            depth.push_back(d);
        }
        if (root->right) {
            dfs(root->right,d+1);
            eulers.push_back(root);
            depth.push_back(d);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, 0);

        int l = first[p];
        int r = first[q];

        if (l > r)
            swap(l, r);
        TreeNode* ans = nullptr;
        int minDepth = INT_MAX;

        for (int i = l; i <= r; i++) {
            if (minDepth > depth[i]) {
                minDepth = depth[i];
                ans = eulers[i];
            }
        }
        return ans;
    }
};