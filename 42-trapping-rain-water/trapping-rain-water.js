/*
 * @lc app=leetcode id=42 lang=javascript
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let leftBarrier = [],rightBarrier = [];
    const n = height.length;

    leftBarrier[0] = height[0]
    for(let i=1;i<n;i++){
        leftBarrier[i] = Math.max(leftBarrier[i-1],height[i]);
    }

    rightBarrier[n-1] = height[n-1];
    for(let i=n-2;i>=0;i--){
        rightBarrier[i] = Math.max(rightBarrier[i+1],height[i]);
    }

    let totalWater = 0;
    for(let i=0;i<n;i++){
        const trapped = Math.min(leftBarrier[i],rightBarrier[i])-height[i];
        if(trapped>0)
            totalWater+=trapped;
    }
    return totalWater;
};
// @lc code=end

