// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start

class Solution {
  private:
    int res = 0;
    void find(TreeNode *root, int low, int high) {
        if (!root)
            return;
        if (root->val < low)
            find(root->right, low, high);
        else if (root->val > high)
            find(root->left, low, high);
        else {
            res += root->val;
            find(root->left, low, high);
            find(root->right, low, high);
        }
    }

  public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        find(root, low, high);
        return res;
    }
};
// @leet end
