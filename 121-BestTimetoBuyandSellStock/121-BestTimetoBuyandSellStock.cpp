// Last updated: 4/19/2025, 1:57:57 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        int minprice = prices[0];
        for(int i=1;i<n;i++){

            maxprofit = max(maxprofit,prices[i]-minprice);
            minprice = min(minprice,prices[i]);
            
        }
        return maxprofit;
    }
};