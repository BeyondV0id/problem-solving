#include <algorithm>
using namespace std;

class Solution {
private:
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int lval = height(root->left);
        if (lval == -1)
            return -1;

        int rval = height(root->right);
        if (rval == -1)
            return -1;

        if (abs(lval - rval) > 1)
            return -1;

        return max(lval, rval) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
