// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), cmp);

        int intial = 0;
        int totalEng = 0;
        for (auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            if (totalEng < minimum) {
                int required = minimum - totalEng;
                intial += required;
                totalEng += required;
            }
            totalEng -= actual;
        }
        return intial;
    }
};
// @leet end
