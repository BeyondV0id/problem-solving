var reverse = function(x) {
    const isNeg = x < 0;
    x = Math.abs(x);
    let s = 0;

    while (x > 0) {
        let r = x % 10;
        s = s * 10 + r;
        x = Math.floor(x / 10);
    }

    if (isNeg) s = -s;

    const MIN = -(2 ** 31);
    const MAX = (2 ** 31) - 1;

    return s < MIN || s > MAX ? 0 : s;
};
