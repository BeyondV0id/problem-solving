class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        vector<pair<int, int>> arr;

        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            arr.push_back({start, +1});
            arr.push_back({end, -1});
        }

        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first < b.first;

            return a.second > b.second;
        });

        long long active = 0;
        long long inter = 0;

        for (auto [n, sign] : arr) {
            if (sign == +1) {
                inter += active;
                active++;
            } else {
                active--;
            }
        }
        return inter;
    }
};