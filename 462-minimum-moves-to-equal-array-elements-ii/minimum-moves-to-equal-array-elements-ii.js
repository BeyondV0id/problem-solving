/*
 * @lc app=leetcode id=462 lang=javascript
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
    let cnt = 0;
    const n = nums.length;
    nums.sort((a,b) => a-b);
    const target = nums[Math.floor(n/2)];
    for (let i = 0; i < n; i++) {
        cnt += Math.abs(nums[i]-target);
    }
    return cnt;

    
};
// @lc code=end

