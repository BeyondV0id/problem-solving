 // @leet start
/**
 * @param {number[]} nums
 */
var Solution = function(nums) {
    this.nums = nums;
    
};

/** 
 * @param {number} target
 * @return {number}
 */
Solution.prototype.pick = function(target) {
    let indices = [];
    for(let i = 0;i< this.nums.length;i++){
        if(this.nums[i] === target)
            indices.push(i);
    }
    let randomIndex = Math.floor(Math.random()*indices.length);
    return indices[randomIndex];
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.pick(target)
 */
// @leet end
