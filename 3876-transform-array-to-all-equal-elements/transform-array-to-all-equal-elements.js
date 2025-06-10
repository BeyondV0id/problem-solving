/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var canMakeEqual = function(nums, k) {
    let check = (req)=>{
        let arr = [...nums];
        let cnt = 0;
        for(let i = 0;i<arr.length-1;i++){
            if(arr[i]!=req){
                arr[i] *= -1;
                arr[i+1] *= -1;
                cnt++;
            }
        }
        for(const num of arr)
            if(num!==req)return false;
        return cnt<=k;
    }; 
    return check(1) || check(-1);
}