class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy = INT_MAX;
        int sell = INT_MIN;

        buy = prices[0];
        sell = prices[0];

        for (int i = 1; i < n; i++) {
            sell = prices[i];
            buy = min(buy, prices[i]);
            maxProfit = max(sell - buy, maxProfit);
        }
        return maxProfit;
    }
};