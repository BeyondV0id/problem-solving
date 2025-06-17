/*
 * @lc app=leetcode id=22 lang=javascript
 *
 * [22] Generate Parentheses
 */

// @lc code=start
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let result = [];
    function backtrack(openCnt,closeCnt,subSol){
        if(subSol.length === 2*n){
            result.push(subSol.join(''));
            return;
        }
        if(openCnt < n){
            subSol.push('(');
            backtrack(openCnt+1,closeCnt,subSol);
            subSol.pop();
        }
        if(closeCnt < openCnt){
            subSol.push(')');
            backtrack(openCnt,closeCnt+1,subSol);
            subSol.pop();
        }

        
    }
    backtrack(0,0,[]);
    return result;
};
// @lc code=end

