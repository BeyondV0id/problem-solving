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
    vector<string>res;
    void dfs(TreeNode* root, string path){
        if(!root)return;

        path += to_string(root->val);

        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }

        path += "->";

        dfs(root->left,path);
        dfs(root->right,path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;

        dfs(root,path);
        return res;
        
    }
};