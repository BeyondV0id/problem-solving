/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @param {number} d
 * @return {number}
 */
var findTheDistanceValue = function(arr1, arr2, d) {
    let cnt = 0;
    for(let x of arr1){
        let flag = 1;
        for(let y of arr2){
            if(Math.abs(x-y)<=d)
                flag = 0;
        }
        if(flag)
            cnt++;
    }
        return cnt;
    };