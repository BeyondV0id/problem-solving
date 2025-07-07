/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function(a, b) {
    while(b!==0){
    const sum = a^b;
    const carry = (a&b)<<1;
    b = carry;
    a = sum;
    }
    return a;
};