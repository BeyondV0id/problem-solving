/**
 * @param {string} s
 * @return {string}
 */
var processStr = function(s) {
    let res = [];
    for(const c of s){
        if(c === '*'){
            if(res.length > 0)
                res.pop();

        }
        else if(c==='#'){
            res = res.concat(res);

        }
        else if(c==='%'){
            res.reverse();
        }
        else
            res.push(c);
    }
    return res.join('');

    
};