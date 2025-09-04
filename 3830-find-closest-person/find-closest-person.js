/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {number}
 */
var findClosest = function (x, y, z) {

    if (Math.abs(x - z) == Math.abs(y - z)) return 0;
    return (Math.abs(x - z) > Math.abs(y - z) ? 2 : 1);
};