/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
private:
    stack<int>stk;
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        for(int i=0;i<asteroids.size();i++){
            bool destroyed = false;
            if (stk.empty() || asteroids[i] > 0 || stk.top() < 0) stk.push(asteroids[i]);
            else{
                while (!stk.empty() && stk.top() > 0){
                    if (stk.top() == -asteroids[i]) {
                        stk.pop();
                        destroyed = true;
                        break;
                    }
                    else if (abs(stk.top()) < abs(asteroids[i])){
                        stk.pop();
                        continue;
                    }
                    else{
                        destroyed = true;
                        break;
                    }
                }
                if(!destroyed)
                    stk.push(asteroids[i]);
            }
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
// @lc code=end

