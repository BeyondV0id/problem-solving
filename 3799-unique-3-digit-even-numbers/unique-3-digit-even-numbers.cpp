/*
 * @lc app=leetcode id=3483 lang=cpp
 *
 * [3483] Unique 3-Digit Even Numbers
 */

// @lc code=start
#include <cmath>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
    int cnt = 0;
    unordered_set<int> isUnique;
    bool isValid(int x) { return (x >= 100 && x <= 999 && x % 2 == 0); }

public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == j || k == i)
                        continue;
                    int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (isValid(number) && !isUnique.count(number)){
                        isUnique.insert(number);
                        cnt++;
                    }

                }
            }
        }
        return cnt;
    }
};
// @lc code=end
