// @leet start
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function (root) {
  const res = [];
  const freq = new Map();
  const dfs = (node) => {
    if (!node) return 'null';
    const lnode = dfs(node.left);
    const rnode = dfs(node.right);
    const arr = node.val + ',' + lnode + ',' + rnode;
    freq.set(arr, (freq.get(arr) || 0) + 1);
    if (freq.get(arr) === 2) res.push(node);
    return arr;
  };
  dfs(root);
  return res;
};
// @leet end
