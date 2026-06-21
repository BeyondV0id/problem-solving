// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (lights[i] != 0) {
                int v = lights[i];
                int mini = max(0, i - v);
                int maxi = min(n - 1, i + v);
                diff[mini] += 1;
                diff[maxi + 1] -= 1;
            } else {
                continue;
            }
        }
        int cnt = 0;
        vector<int> vis(n, 0);

        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        int i = 0;
        while (i < n) {
            if (diff[i] != 0) {
                i++;
                continue;
            } else {
                cnt++;
                i += 3;
            }
        }
        return cnt;
    }
};
