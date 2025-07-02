var reverse = function(x) {
    let isNegative = false;
    let reversed = 0;
    if(x<0){
        isNegative = true;
        x = x*-1;
    }
    while(x>0){
        reversed = reversed*10 + x % 10;
        x = Math.floor(x/10);
    }
    if(isNegative)
        reversed *= -1;
    if(reversed < -(2**31) || reversed > (2**31 -1 ))
        return 0;
    return reversed;    
};
// @lc code=end

