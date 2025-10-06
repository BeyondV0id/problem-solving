// @leet start
/**
 * @param {number[]} groupSizes
 * @return {number[][]}
 */
var groupThePeople = function(groupSizes) {
  const res = [];
  const n = groupSizes.length;
  const grpMap = new Map();
  for(let i = 0; i < n; i++){
    let grpSize = groupSizes[i];
    if(!grpMap.has(grpSize)){
      grpMap.set(grpSize,[]);
    }
    grpMap.get(grpSize).push(i);
    if(grpMap.get(grpSize).length === grpSize){
      res.push(grpMap.get(grpSize));
      grpMap.set(grpSize,[]);
    }
  }
  return res;
};
// @leet end
