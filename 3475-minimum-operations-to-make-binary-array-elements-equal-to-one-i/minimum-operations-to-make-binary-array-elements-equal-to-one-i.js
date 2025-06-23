var minOperations = function (nums) {
    let cnt = 0;
    for (let i = 0; i < nums.length - 2; i++) {
        if (nums[i] === 0) {
            nums[i] = 1;
            nums[i + 1] = nums[i + 1] === 1 ? 0 : 1;
            nums[i + 2] = nums[i + 2] === 1 ? 0 : 1;
            cnt++;
        }
    }
    const allAreOne = nums.filter(x => x === 1).length === nums.length;
    return allAreOne ? cnt : -1;


};
// @lc code=end

