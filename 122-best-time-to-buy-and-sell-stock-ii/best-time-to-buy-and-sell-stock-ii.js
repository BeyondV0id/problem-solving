/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let totalProfit = 0;
    let maxprofit = -1;
    let maxNumber = prices[0];
    let minElement = prices[0];
    for (let i = 1; i < prices.length; i++) {
        if(prices[i]>maxNumber){
            maxprofit = Math.max(maxprofit, prices[i]-minElement);
            maxNumber = Math.max(maxNumber,prices[i]);
        }
        else{
            if(maxprofit != -1)
                totalProfit+=maxprofit;
            minElement = prices[i];
            maxNumber = prices[i];
            maxprofit = -1;
        }
    }
     if (maxprofit !== -1) {
        totalProfit += maxprofit;
    }
    return totalProfit;    
};