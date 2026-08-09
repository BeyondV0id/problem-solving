class Solution {
private:
    double applyDiscount(int p, int d) {
        return (1.0 * p * (100 - d)) / 100.0;
    }

public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        double totalPrice = 0.0;
        int j = 0;

        for (int i = 0; i < discounts.size(); i++) {
            if (j < prices.size()) {
                totalPrice += applyDiscount(prices[j++], discounts[i]);
            } else {
                break;
            }
        }

        for (int i = j; i < prices.size(); i++) {
            totalPrice += prices[i];
        }

        return totalPrice;
    }
};