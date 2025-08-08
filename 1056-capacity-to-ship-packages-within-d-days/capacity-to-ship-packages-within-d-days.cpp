#include <algorithm>
#include <string>
#include <vector>
class Solution {
private:
    int how_many_days(int capacity,vector<int>&weights) {
        int needed_days = 1;
        int current_load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (current_load + weights[i] <= capacity) {
                current_load += weights[i];
            } else {
                current_load = weights[i];
                needed_days++;
            }
        }
        return needed_days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min_weight, max_weight;
        min_weight = *max_element(weights.begin(), weights.end());
        max_weight = accumulate(weights.begin(), weights.end(), 0);

        while (min_weight < max_weight) {
            int req_ship_weight = (min_weight) + (max_weight - min_weight) / 2;
            if (how_many_days(req_ship_weight,weights) <= days)
                max_weight = req_ship_weight;
            else {
                min_weight = req_ship_weight + 1;
            }
        }
        return min_weight;
    }
};
