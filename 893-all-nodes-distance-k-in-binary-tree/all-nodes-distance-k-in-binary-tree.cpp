class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> getParent;
    void helper(TreeNode* root) {
        if (root == nullptr)
            return;

        if (root->left) {
            getParent[root->left] = root;
            helper(root->left);
        }
        if (root->right) {
            getParent[root->right] = root;
            helper(root->right);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_set<TreeNode*> visited;
        helper(root);

        queue<TreeNode*> q;
        q.push(target);

        while (!q.empty() and k) {
            k--;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                visited.insert(node);
                if (!visited.count(getParent[node]) && getParent[node]) {
                    q.push(getParent[node]);
                }
                if (!visited.count(node->left) and node->left) {
                    q.push(node->left);
                }
                if (!visited.count(node->right) and node->right) {
                    q.push(node->right);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};
