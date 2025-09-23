// @leet start
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    let s1 = version1.split('.').map(Number);
    let s2 = version2.split('.').map(Number);
    const maxLen = Math.max(s1.length,s2.length);
    while(s1.length < maxLen)s1.push(0);
    while(s2.length < maxLen)s2.push(0);

    for(let i=0;i<maxLen;i++){
        if(s1[i] > s2[i])
            return 1;
        if(s1[i] < s2[i])
            return -1;
        else continue;
    }
    return 0;



    
};
// @leet end
