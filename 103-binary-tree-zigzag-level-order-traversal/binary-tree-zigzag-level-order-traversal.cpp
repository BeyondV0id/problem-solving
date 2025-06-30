class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        vector<vector<int>>res;
        int level = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>subarray;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node= q.front();
                if(level%2 == 0){
                    subarray.insert(subarray.begin(),node->val);
                }
                else
                    subarray.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
            level++;
            res.push_back(subarray);
        }
        return res;

        
    }
};
// @lc code=end

