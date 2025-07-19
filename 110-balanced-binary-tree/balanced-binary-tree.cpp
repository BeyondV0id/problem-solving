
#include<algorithm>
using namespace std;
class Solution {
private:
    int height(TreeNode* root){
        if(!root)
            return 0;
        int lval = height(root->left);
        int rval = height(root->right);
        if(rval == -1 || lval == -1)
            return -1;
        if(abs(rval-lval)> 1)
            return -1;
        return 1+max(height(root->left),height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};
// @lc code=end

