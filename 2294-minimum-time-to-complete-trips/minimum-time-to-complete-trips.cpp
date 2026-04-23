// @leet imports start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
    long long tripsTaken(int low, int high, vector<int>& time, long long givenTime,int totalTrips) {
        long long trips = 0;
        for (int i = 0; i < (int)time.size(); i++) {
            trips += givenTime / time[i];

            if (trips >= totalTrips)
                return trips;
        }
        return trips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long minTime = *min_element(time.begin(), time.end());

        long long low = 1;
        long long high = minTime * totalTrips;

        while (low < high) {
            long long mid = (low + high) / 2;
            long long trips = tripsTaken(low, high, time, mid,totalTrips);

            if (trips >= totalTrips) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// @leet end
