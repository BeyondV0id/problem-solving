/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chem = 0;
        sort(skill.begin(),skill.end());
        int req = skill[0] + skill[skill.size()-1];
        int l = 0,r=skill.size()-1;
        while(l<r){
            int sum = skill[l]+skill[r];
            if(sum!=req)
                return -1;
            chem += skill[l]*skill[r];
            l++;
            r--;
        }
        return chem;   
    }
};
// @lc code=end

