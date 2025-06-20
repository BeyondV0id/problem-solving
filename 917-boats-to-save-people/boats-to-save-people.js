var numRescueBoats = function (people, limit) {
    people.sort((a, b) => a - b);
    let cnt = 0;
    let l = 0,
        r = people.length-1;
    while (l <= r) {
        const total = people[l] + people[r];
        if (total <= limit) {
            cnt++;
            l++;
            r--;
        }
        else {
            cnt++;
            r--;
        }
    }
    return cnt;



};
// @lc code=end

