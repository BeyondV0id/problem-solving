/**
 * @param {string} answerKey
 * @param {number} k
 * @return {number}
 */
var maxConsecutiveAnswers = function (answerKey, k) {
  let freq = new Map();
  let len = answerKey.length;
  let l = 0,
    r = 0;
  let maxWindow = -Infinity;
  while (r < len) {
    let char = answerKey[r++];
    freq.set(char, (freq.get(char) || 0) + 1);
    let maxFreq = Math.max(...freq.values());
    while(r-l-maxFreq > k){
      freq.set(answerKey[l], (freq.get(answerKey[l]))-1);
      if(freq.get(answerKey[l]) === 0)
        freq.delete(answerKey[l]);
      l++;
    }
    maxWindow = Math.max(maxWindow,r-l);
  }
  return maxWindow;
};