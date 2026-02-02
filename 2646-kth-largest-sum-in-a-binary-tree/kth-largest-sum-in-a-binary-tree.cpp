// @leet imports start
#include <bits/stdc++.h>
#include <queue>
using namespace std;
// @leet imports end

// @leet start


class Solution {
  private:
    priority_queue<long long, vector<long long>, greater<long long>> minH;
    long long bfs(TreeNode *root, int k) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            long long levelSum = 0;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            minH.push(levelSum);
            if ((int)minH.size() > k) {
                minH.pop();
            }
        }
        if((int)minH.size() < k)return -1;
        return minH.top();
    }

  public:
    long long kthLargestLevelSum(TreeNode *root, int k) { return bfs(root, k); }
};
// @leet end

