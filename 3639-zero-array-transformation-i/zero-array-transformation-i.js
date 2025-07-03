/*
 * @lc app=leetcode id=3355 lang=javascript
 *
 * [3355] Zero Array Transformation I
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean}
 */
var isZeroArray = function(nums, queries) {
    const n = nums.length;
    const diff = new Array(n+1).fill(0);

    for(const [l,r] of queries){
        diff[l] += 1; 
        if(r+1<n)
            diff[r+1] -= 1;
    }
    const coverage = new Array(n+1).fill(0);
    coverage[0] = diff[0];
    for(let i=1;i<n;i++){
        coverage[i] = coverage[i-1] + diff[i];
    }
    for(let i=0;i<n;i++){
        if(coverage[i] < nums[i])
            return false;
    }
    return true;
    
};
// @lc code=end

