/*
 * @lc app=leetcode id=438 lang=javascript
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function (s, p) {
    const windowSize = p.length, size = s.length;
    const res = [];
    let isValidAnagram = (l, r) => {
        const count = {}
        const str1 = s.slice(l, r + 1).split('').join('');
        for (let c of str1) {
            count[c] = (count[c] || 0) + 1;
        }
        for (let c of p) {
            if (!count[c]) return false;
            count[c]--;
        }
        return true;
    }
    let l = 0, r = 0;
    while (r < size) {
        if (windowSize === (r - l + 1) && isValidAnagram(l, r)) {
            res.push(l);
            l++
        }
        r++;
    }
    return res;



};
// @lc code=end

var findAnagrams = function (s, p) {
    const windowSize = p.length, size = s.length;
    const res = [];

    if (size < windowSize) return res;
    const pCount = {}, sCount = {};

    for (let c of p) {
        pCount[c] = (pCount[c] || 0) + 1;
    }

    for (let i = 0; i < windowSize; i++) {
        let c = s[i];
        sCount[c] = (sCount[c] || 0) + 1;
    }

    let isValidAnagram = () => {
        for (let c in pCount) {
            if (pCount[c] !== sCount[c]) return false;
        }
        return true;
    }

    let l = 0, r = windowSize - 1;
    if (isValidAnagram()) res.push(l);
    r++;
    while (r < size) {
        sCount[s[r]] = (sCount[s[r]] || 0) + 1;
        sCount[s[l]]--;
        if (sCount[s[l]] === 0)
            delete sCount[s[l]];
        l++;
        if (isValidAnagram())
            res.push(l);
        r++;
    }

    return res;
};
