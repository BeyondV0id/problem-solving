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
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        int maxSum = INT_MIN;
        int curLvl = 1;
        int res = 1;

        while(!q.empty()){
            int curSum = 0;
            int n = q.size();


            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                curSum += node->val;

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
            if(maxSum < curSum){
                maxSum = curSum;
                res = curLvl;
            }
            curLvl++;
        }
        return res;
    }

};