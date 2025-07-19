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
    let t = [];
    let vowels = [];
    let isVowel = (char)=>{
        return  'aeiouAEIOU'.includes(char);
    }
    for(const char of s){
        if(isVowel(char)){
            vowels.push(char);
        }
    }
    vowels.sort();
    let i = 0;
    for(const char of s){
        if(!isVowel(char)){
            t.push(char);
        }
        else{
            t.push(vowels[i++]);
        }
    }
    return t.join('');
    
};
// @lc code=end

