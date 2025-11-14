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
    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r)
            return nullptr;
        int maxIndx = l;
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] > nums[maxIndx]) {
                maxIndx = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIndx]);
        root->left = dfs(nums, l, maxIndx - 1);
        root->right = dfs(nums, maxIndx + 1, r);
        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};
// @leet end
