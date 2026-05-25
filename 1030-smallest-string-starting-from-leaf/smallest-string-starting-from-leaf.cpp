// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start

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
    string res = "";
    void dfs(TreeNode* root, string curr) {
        if (!root)
            return;

        curr = char('a' + root->val) + curr;

        if (!root->left && !root->right) {
            if (res == "" || curr < res) {
                res = curr;
            }
            return;
        }
        dfs(root->left,curr);
        dfs(root->right,curr);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return res;
    }
};
