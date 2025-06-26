class Solution {
private:
    void reverseInorder(TreeNode *root,int &sum){
        if(root == nullptr)return;
        reverseInorder(root->right,sum);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left,sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        reverseInorder(root,sum);
        return root;


    }
};
// @lc code=end

