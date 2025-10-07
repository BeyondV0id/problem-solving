// @leet start
/**
 * @param {number[]} barcodes
 * @return {number[]}
 */
var rearrangeBarcodes = function (barcodes) {
    const res = [];
    const f = new Map();
    let maxFreq = 0;
    let maxNum = null;
    for (const barcode of barcodes) {
        f.set(barcode, (f.get(barcode) || 0) + 1);
        if (f.get(barcode) > maxFreq) {
            maxFreq = f.get(barcode);
            maxNum = barcode;
        }
    }
    let i = 0;
    while (maxFreq--) {
        res[i] = maxNum;
        i += 2;
        if (i > barcodes.length - 1)
            i = 1;
    }
    f.delete(maxNum);

    for (const [num, frq] of f) {
        let c = frq
        while (c--) {
            res[i] = num;
            i += 2;
            if (i > barcodes.length-1) i = 1;
        }
    }
    return res;

};
// @leet end
