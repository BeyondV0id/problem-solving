/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string res = "{";
    void dfs(TreeNode *root,string cur){

        if(!root)return;

        cur = char('a' + (root->val)) + cur;

        if(!root->left && !root->right){
            res = min(res,cur);
            return;
        }


        dfs(root->left,cur);
        dfs(root->right,cur);

        
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string cur;
        dfs(root,cur);
        return res;
    }
};