class Solution {
public:

    void inorder(TreeNode* root, vector<int>& arr) {

        if(root == NULL) return;

        inorder(root->left, arr);

        arr.push_back(root->val);

        inorder(root->right, arr);
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {

        vector<int> ans;

        int i = 0;
        int j = 0;

        while(i < a.size() && j < b.size()) {

            if(a[i] <= b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        while(i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        while(j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> a;
        vector<int> b;

        inorder(root1, a);
        inorder(root2, b);

        return merge(a, b);
    }
};