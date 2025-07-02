/*
 * @lc app=leetcode id=1456 lang=javascript
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function(s, k) {
    let cnt = 0,maxCnt = -Infinity;
    const n = s.length;
    let l=0,r=0;
    function isVowel(char){
        return 'aeiou'.includes(char);
    }
    while(r<n){
        const char = s[r++];
        if(isVowel(char))
            cnt++;
        while(r-l > k){
            if(isVowel(s[l]))
                cnt--;
            l++;
        }
        maxCnt = Math.max(maxCnt,cnt);

    }
    return maxCnt;
};
// @lc code=end

