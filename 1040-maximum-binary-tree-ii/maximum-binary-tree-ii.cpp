// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//     right(right) {}
// };
class Solution {
private:
    void ArrayBuilder(TreeNode* root, vector<int>& nums) {
        if (!root)
            return;
        ArrayBuilder(root->left, nums);
        nums.push_back(root->val);
        ArrayBuilder(root->right, nums);
    }
    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r)
            return nullptr;
        int maxIndx = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] > nums[maxIndx])
                maxIndx = i;
        }
        TreeNode* root = new TreeNode(nums[maxIndx]);
        root->left = dfs(nums, l, maxIndx - 1);
        root->right = dfs(nums, maxIndx + 1, r);
        return root;
    }

public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(0);
        vector<int> nums;
        ArrayBuilder(root, nums);
        nums.push_back(val);
        return dfs(nums, 0, nums.size() - 1);
    }
};
// @leet end
