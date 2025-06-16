/*
 * @lc app=leetcode id=424 lang=javascript

 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    let l = 0,r = 0;
    const len = s.length;
    const freq = new Map();
    let maxWindow = -Infinity;
    while(r<len){
        const char = s[r++];
        freq.set(char,(freq.get(char) || 0)+1);
        maxfreq = Math.max(...freq.values());
        while((r-l)-maxfreq > k){
            freq.set(s[l],freq.get(s[l]) - 1);
            if(freq.get(s[l]) === 0)
                freq.delete(s[l]);
            l++;
        }
        maxWindow = Math.max(maxWindow, r-l);
    }
    return maxWindow;
};
// @lc code=end

