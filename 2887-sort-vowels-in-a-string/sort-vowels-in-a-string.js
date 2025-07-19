/*
 * @lc app=leetcode id=2785 lang=javascript
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string}
 */
var sortVowels = function(s) {
    const vowels = new Set(
        ['a','e','i','o','u','A','E','I','O','U']
     );
   const strArr = s.split('');
   const vowelIndxs = [];
   const vowelArr = [];

   for(let i=0;i<strArr.length;i++)
        if(vowels.has(strArr[i])){
            vowelArr.push(strArr[i]);
            vowelIndxs.push(i);
        }
    vowelArr.sort();
    for(let i=0;i<vowelIndxs.length;i++){
        strArr[vowelIndxs[i]] = vowelArr[i];
    }
    return strArr.join('');
   
};
// @lc code=end

