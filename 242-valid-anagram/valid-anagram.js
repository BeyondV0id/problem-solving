/*
 * @lc app=leetcode id=242 lang=javascript
 *
 * [242] Valid Anagram
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    const c1 = {},c2 = {};

    for (let c of s) {
      c1[c] = (c1[c] || 0) + 1;
    }
    for(let c of t){
        c2[c] = (c2[c] || 0) + 1;
    }
    for(let key in c1){
        if(c1[key] !== c2[key])return false;
    }
    for(let key in c2){
        if(c1[key]!==c2[key])return false;
    }
    return true;
};
// @lc code=end

