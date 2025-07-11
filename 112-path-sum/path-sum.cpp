
#include<vector>
using namespace std;
class Solution {
private:
    bool pathSum = false;
    void dfs(TreeNode*root, int target){
        if(root==nullptr)
            return;
        if(!root->left && !root->right && target-root->val == 0)
            pathSum = true;
        TreeNode* node = root;
        const int val = node->val;
        dfs(node->left,target-val);
        dfs(node->right,target-val);
        

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return pathSum;
    }
};
// @lc code=end

