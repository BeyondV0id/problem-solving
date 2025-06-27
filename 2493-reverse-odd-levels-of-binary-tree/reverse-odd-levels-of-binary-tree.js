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
 * @return {TreeNode}
 */
var reverseOddLevels = function(root) {
    if(!root)return null;
    let level = 0;
    const queue = [root];
    while(queue.length > 0){
        const reverse = [];
        const len = queue.length;
        for(let i=0;i<len;i++){
            const node = queue.shift();
            reverse.push(node);
            if(node.left)queue.push(node.left);
            if(node.right)queue.push(node.right);
        }
        if(level%2===1){
            let l = 0,r=reverse.length-1;
            while(l<r){
                [reverse[l].val,reverse[r].val] = [reverse[r].val,reverse[l].val];
                l++;
                r--;
            }
        }
        level++;
    }
    return root;


};
// @lc code=end

