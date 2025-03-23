// Last updated: 3/23/2025, 11:21:12 AM
#include <vector>
#include <algorithm>  // For max_element
#include <cmath>      // For ceil

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high; // Store the minimum possible eating speed
        
        while (low <= high) {
            int mid = (low + high) / 2;
            long long reqTime = helper(piles, mid);
            
            if (reqTime <= h) {
                ans = mid;  // Store possible answer
                high = mid - 1; // Try a smaller speed
            } else {
                low = mid + 1;  // Increase speed
            }
        }
        return ans;
    }

    long long helper(vector<int>& piles, int hour_rate) {
        long long totalTime = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalTime += ceil((double)piles[i] / hour_rate);
        }
        return totalTime;
    }
};
