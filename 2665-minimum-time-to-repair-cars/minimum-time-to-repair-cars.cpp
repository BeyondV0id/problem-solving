// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {

    bool canRepair(long long time, vector<int>& ranks, int cars) {

        long long totalCars = 0;

        for(int i = 0; i < ranks.size(); i++) {

            totalCars += sqrt(time / ranks[i]);

            if(totalCars >= cars) {
                return true;
            }
        }

        return totalCars >= cars;
    }

public:

    long long repairCars(vector<int>& ranks, int cars) {

        long long l = 1;

        long long mn = *min_element(ranks.begin(), ranks.end());

        long long r = mn * cars * cars;

        while(l < r) {

            long long mid = l + (r - l) / 2;

            if(canRepair(mid, ranks, cars)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};
// @leet end