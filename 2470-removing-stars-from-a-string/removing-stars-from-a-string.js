// @leet start
/**
 * @param {string} s
 * @return {string}
 */
var removeStars = function(s) {
  let n = s.length;
  let stk = [];
  for(let i=0;i<n;i++){
    if(s[i] != '*')
      stk.push(s[i]);
    else{
      if(stk.length !== 0){
        stk.pop();
      }
    }
  }
  return stk.join('');

    
};
// @leet end
