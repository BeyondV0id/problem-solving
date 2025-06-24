var findMatrix = function(nums) {
    const freq = new Map();
    for (const num of nums) {
        freq.set(num, (freq.get(num) || 0) + 1);
    }
    const rows = Math.max(...[... freq.values()]);
    const res = [];
    for (let i = 0; i < nums.length; i++) {
        let cnt = freq.get(nums[i]);
        while (res.length < cnt)
            res.push([]);
        res[cnt - 1].push(nums[i]);
        freq.set(nums[i], cnt - 1);
    }
    return res;
};
// @lc code=end
