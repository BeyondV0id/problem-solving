/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        for (int i = 0; i < position.size(); i++)
            cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });
        vector<double> timeReq;
        for (int i = 0; i < position.size(); i++)
            timeReq.push_back((double)(target-cars[i].first)/cars[i].second);
        //{1, 1, 7, 3, 12}
        stack<double> res;
        for (int i = 0; i < position.size(); i++){
            if(res.empty() || res.top()<timeReq[i])
                res.push(timeReq[i]);
        }
        return res.size();
    }
};
// @lc code=end

