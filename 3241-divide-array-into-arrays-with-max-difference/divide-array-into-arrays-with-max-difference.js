/*
 * @lc app=leetcode id=2966 lang=javascript
 *
 * [2966] Divide Array Into Arrays With Max Difference
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[][]}
 */
var divideArray = function(nums, k) {
    let result = [];
    nums.sort((a,b)=>a-b);
    for(let i = 0; i < nums.length;i+=3){
        let a = nums[i];
        let b = nums[i+1];
        let c = nums[i+2];
        if(c-a <=k)
            result.push([a,b,c]);
        else
            return [];
    }
    return result;



    
};
// @lc code=end

