// @leet start
/**
 * Definition for a binary tree node.
  function TreeNode(val, left, right) {
      this.val = (val===undefined ? 0 : val)
      this.left = (left===undefined ? null : left)
      this.right = (right===undefined ? null : right)
  }
 * @param {TreeNode} root
 * @return {number[]}
 */
function TreeNode(val, left, right) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}
var rightSideView = function (root) {
    let res = [];
    if (!root) return res;
    let q = [root];

    while (q.length > 0) {
        let rsvNode = null;
        let size = q.length;
        for (let i = 0; i < size; i++) {
            let node = q.shift();
            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
            rsvNode = node;
        }
        if (rsvNode) res.push(rsvNode.val);
    }
    return res;
};
// @leet end

