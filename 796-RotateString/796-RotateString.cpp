// Last updated: 4/4/2025, 5:47:15 PM
/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;

        for(int i=0;i<s.size();i++){
            string rotated;
            for(int j=0;j<s.size();j++){
                int newIndex = (j+i)%s.size();
                rotated+=s[newIndex];
            }
            if(rotated == goal)return true;
    }
    return false;
    }

};
// @lc code=end

