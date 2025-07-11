#include<vector>
using namespace std; 
class Solution {
private:
    void dfs(TreeNode*root,int targetSum,vector<vector<int>>&result,
        vector<int>&path){
            if(!root)return;
            if(!root->left && !root->right && root->val == targetSum){
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
                return;
            }
            TreeNode* node = root;
            path.push_back(node->val);
            dfs(root->left,targetSum-node->val,result,path);
            dfs(root->right,targetSum-node->val,result,path);
            path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>path;
        dfs(root,targetSum,result,path);
        return result;
        
    }
};
// @lc code=end

