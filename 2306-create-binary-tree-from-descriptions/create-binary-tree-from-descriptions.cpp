class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> nodes;
        unordered_set<int> children;

        unordered_map<int, vector<pair<int, bool>>> myChildren;

        for (auto it : descriptions) {
            int parent = it[0];
            int child = it[1];
            bool isLeft = it[2];

            nodes.insert(parent);
            nodes.insert(child);

            children.insert(child);

            myChildren[parent].push_back({child, isLeft});
        }

        int rootVal;

        for (auto node : nodes) {
            if (!children.count(node)) {
                rootVal = node;
                break;
            }
        }

        unordered_map<int, TreeNode*> mp;

        for (auto node : nodes) {
            mp[node] = new TreeNode(node);
        }

        for (auto node : nodes) {

            if (!myChildren.count(node))
                continue;

            for (auto [child, isLeft] : myChildren[node]) {

                if (isLeft)
                    mp[node]->left = mp[child];
                else
                    mp[node]->right = mp[child];
            }
        }

        return mp[rootVal];
    }
};