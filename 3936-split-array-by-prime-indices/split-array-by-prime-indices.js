/**
 * @param {number[]} nums
 * @return {number}
 */
var splitArray = function (nums) {
    let sumofA = 0;
    let sumofB = 0;

    function isPrimeIndx(num) {
        if (num <= 1)
            return false;
        for (let i = 2; i * i <= num; i++) {
            if (num % i === 0)
                return false;
        }
        return true;
    }
    for (let i = 0; i < nums.length; i++) {
        if (isPrimeIndx(i)) {
            sumofA += nums[i]
        }
        else
            sumofB += nums[i];
    }
    return Math.abs(sumofB - sumofA);
}
