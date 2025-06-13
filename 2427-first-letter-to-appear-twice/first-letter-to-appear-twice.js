/*
 * @lc app=leetcode id=2351 lang=javascript
 *
 * [2351] First Letter to Appear Twice
 */

// @lc code=start
/**
 * @param {string} s
 * @return {character}
 */
var repeatedCharacter = function(s) {
    const seen = new Set();
    for(const c of s){
        if(seen.has(c))
            return c
        seen.add(c);
    }
};
// @lc code=end

