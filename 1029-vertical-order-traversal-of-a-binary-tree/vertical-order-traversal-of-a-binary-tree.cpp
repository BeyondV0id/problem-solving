

class Solution {
private:
    map<int, vector<pair<int, int>>> colMap; // col -> [...{val,row}]
                                                       //
    void dfs(TreeNode* root, int row, int col) {
        if (!root)
            return;

        colMap[col].push_back({row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>> res;

        for (auto key : colMap) {
            int col = key.first;
            int n = key.second.size();

            sort(key.second.begin(), key.second.end(), [](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            });

            vector<int> temp;

            for (auto& rowValPair : key.second) {
                int val = rowValPair.second;
                temp.push_back(val);
            }
            res.push_back(temp);
        }
        return res;
    }
};
