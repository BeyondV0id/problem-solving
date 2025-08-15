/*
 * @lc app=leetcode id=71 lang=javascript
 *
 * [71] Simplify Path
 */

// @lc code=start
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    let stk = [];
    let newPath = path.split('/');
    path.split('/').forEach(str=>{
        if(str == "" || str == ".")
            return;
        else if(str == ".."){
            if(stk.length>0)
                stk.pop();
        }
        else
            stk.push(str);
    });
   return "/"+stk.join('/'); 
};
// @lc code=end

