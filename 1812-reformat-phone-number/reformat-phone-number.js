// @leet start
/**
 * @param {string} number
 * @return {string}
 */
var reformatNumber = function(number) {
  let res= "";
  let arr = number.split('');
  let digits = arr.filter(char => char >= '0' && char <="9");
  while(digits.length>4){
    res += digits.splice(0,3).join('') + '-';
  }
  if(digits.length == 4){
        res += digits.splice(0,2).join('') + '-';
        res += digits.splice(0,2).join('');
  }
  else{
        res += digits.join('');
  }
  return res;
    
};
// @leet end
