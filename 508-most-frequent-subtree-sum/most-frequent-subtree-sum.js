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
 * @return {number[]}
 */
var findFrequentTreeSum = function (root) {
  const freq = new Map();
  const dfs = (root) => {
    if (!root) return 0;
    const lval = dfs(root.left);
    const rval = dfs(root.right);
    let sum = lval + rval + root.val;
    freq.set(sum, (freq.get(sum) || 0) + 1);
    //console.log(sum);
    return sum;
  };
  dfs(root);
  let maxFreq = 0;
  for (const frq of freq.values()) if (maxFreq < frq) maxFreq = frq;
  const res = [];
  for (const [sum, cnt] of freq.entries()) if (cnt === maxFreq) res.push(sum);
  return res;
};
// @leet end

