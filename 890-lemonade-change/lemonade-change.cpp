// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {

public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0, c20 = 0;
        int n = bills.size();

        for (int i = 0; i < n; i++) {
            int curr = bills[i];
            if (curr == 5) {
                c5++;
            } else if (curr == 10) {
                if (c5 > 0) {
                    c5--;
                    c10++;
                } else
                    return false;
            } else if (curr == 20) {
                if (c10 > 0 && c5 > 0) {
                    c10--;
                    c5--;
                } else if (c5 > 2) {
                    c5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
