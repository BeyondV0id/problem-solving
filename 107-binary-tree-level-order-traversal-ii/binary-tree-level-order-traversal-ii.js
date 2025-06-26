/*
 * @lc app=leetcode id=107 lang=javascript
 *
 * [107] Binary Tree Level Order Traversal II
 */

// @lc code=start
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
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    if(!root)return [];
    const q = [root];
    const res = [];
    while(q.length>0){
        const level = [];
        const len = q.length;
        for(let i=0;i<len;i++){
            const node = q.shift();
            level.push(node.val);
            if(node.left)q.push(node.left);
            if(node.right)q.push(node.right);
        }
        res.unshift(level);
    }
    return res;

    
};
// @lc code=end

