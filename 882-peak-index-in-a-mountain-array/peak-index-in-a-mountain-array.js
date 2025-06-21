var peakIndexInMountainArray = function (arr) {
    let l = 0, r = arr.length - 1;
    while (l < r) {
        const m = l + Math.floor((r - l) / 2);
        if ((m === 0 || arr[m - 1] < arr[m]) && (m === arr.length - 1 || arr[m] > arr[m + 1]))
            return m;
        else if (arr[m] < arr[m + 1])
            l = m + 1;
        else
            r = m;
    }
    return l;
};

// @lc code=end

