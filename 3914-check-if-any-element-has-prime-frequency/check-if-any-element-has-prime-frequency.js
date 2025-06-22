var checkPrimeFrequency = function(nums) {
    let isPrime= (x)=>{
        if(x<2)return false;
        for(let i=2;i<x;i++)
            if(x%i===0)return false;
        return true;
    }
    const freq = new Map();
    for(const n of nums)
        freq.set(n, (freq.get(n) || 0)+1);
    for(const cnt of freq.values()){
        if(isPrime(cnt))
            return true;
    }
    return false;
};