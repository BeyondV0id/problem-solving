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
 * @return {string}
 */
var tree2str = function (root) {
  const dfs = (node) => {
    if (!node) return '';
    let res = `${node.val}`;
    const lnode = dfs(node.left);
    const rnode = dfs(node.right);
    if (!lnode && !rnode) return res;
    res += `(${lnode})`;
    if (rnode)
      res += `(${rnode})`;
    return res;
  };
  return dfs(root);
};
// @leet end

