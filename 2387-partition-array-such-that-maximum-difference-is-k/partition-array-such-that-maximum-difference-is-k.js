/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var partitionArray = function(nums, k) {
    nums.sort((a, b) => a - b);
    let mini = nums[0];
    // 1 2 3 5 6
    let breakpoint = 1;
    for (let i = 1; i < nums.length; i++) {
        if(nums[i] > k+mini){
            mini = nums[i];
            breakpoint++;
        }
    }
    return breakpoint;

};