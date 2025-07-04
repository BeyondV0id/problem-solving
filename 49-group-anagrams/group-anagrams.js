/*
 * @lc app=leetcode id=49 lang=javascript
 *
 * [49] Group Anagrams
 */

// @lc code=start
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const map = {};
    for(let word of strs){
        const key = word.split('').sort().join('');
        if(!map[key])
            map[key] = [];
        map[key].push(word);
    }
    return Object.values(map);



    
};
// @lc code=end

