/*
 * @lc app=leetcode id=2126 lang=cpp
 *
 * [2126] Destroying Asteroids
 */
// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        bool canbeDestroyed = true;
        long long planetMass = (long long)mass;
        sort(asteroids.begin(), asteroids.end());
        for (int i = 0; i < asteroids.size(); i++) {
            if (planetMass >= asteroids[i]) {
                planetMass += asteroids[i];
            } else {
                canbeDestroyed = false;
                break;
            }
        }

        return canbeDestroyed;
    }
};
