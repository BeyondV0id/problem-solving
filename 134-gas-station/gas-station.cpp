// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIndx = 0;
        int totalCost = 0;
        int totalGas = 0;
        for (int i = 0; i < (int)gas.size(); i++) {
            totalCost += cost[i];
            totalGas += gas[i];
            gas[i] -= cost[i];
        }
        if (totalCost > totalGas)
            return -1;
        // gas = -2 -2 -1 3 1
        int currentGas = 0;
        for (int i = 0; i < (int)gas.size(); i++) {
            currentGas += gas[i];
            if (currentGas < 0) {
                startIndx = i + 1;
                currentGas = 0;
            }
        }
        return startIndx;
    }
};
// @leet end
