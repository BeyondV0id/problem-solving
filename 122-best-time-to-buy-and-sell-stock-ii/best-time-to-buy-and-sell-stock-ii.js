var maxProfit = function(prices) {
    let totalProfit = 0;
    let maxProfitInSegment = -1;
    let currentHigh = prices[0];
    let currentLow = prices[0];

    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > currentHigh) {
            maxProfitInSegment = Math.max(maxProfitInSegment, prices[i] - currentLow);
            currentHigh = prices[i];
        } else {
            if (maxProfitInSegment !== -1) {
                totalProfit += maxProfitInSegment;
            }
            currentLow = prices[i];
            currentHigh = prices[i];
            maxProfitInSegment = -1;
        }
    }

    if (maxProfitInSegment !== -1) {
        totalProfit += maxProfitInSegment;
    }

    return totalProfit;
};
