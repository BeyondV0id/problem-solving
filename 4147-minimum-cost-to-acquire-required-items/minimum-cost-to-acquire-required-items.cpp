class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long totalCost = 0;

        int common;
        if (need1 < need2)
            common = need1;
        else
            common = need2;

        if (costBoth < cost1 + cost2) {
            totalCost += 1LL * common * costBoth;
        } else {
            totalCost += 1LL * common * (cost1 + cost2);
        }

        need1 -= common;
        need2 -= common;

        if (need1 > 0) {
            if (costBoth < cost1)
                totalCost += 1LL * need1 * costBoth;
            else
                totalCost += 1LL * need1 * cost1;
        }

        if (need2 > 0) {
            if (costBoth < cost2)
                totalCost += 1LL * need2 * costBoth;
            else
                totalCost += 1LL * need2 * cost2;
        }

        return totalCost;
    }
};
