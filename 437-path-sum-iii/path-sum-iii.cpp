/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

// @lc code=start
class Solution {
private:
    int cnt = 0;
    long long sum = 0;
    unordered_map<long long, int> preSumMap;
    void dfs(TreeNode* root, int targetSum) {
        if (!root)
            return;
        sum += root->val;
        long long rem = sum - targetSum;
        if (preSumMap.count(rem)) {
            cnt += preSumMap[rem];
        }
        preSumMap[sum]++;
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        preSumMap[sum]--;
        sum -= root->val;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        preSumMap[0] = 1;
        dfs(root, targetSum);
        return cnt;
    }
};
// @lc code=end
