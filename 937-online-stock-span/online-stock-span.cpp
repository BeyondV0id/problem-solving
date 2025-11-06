// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class StockSpanner {
private:
    stack<pair<int, int>> stk;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
    }
};
