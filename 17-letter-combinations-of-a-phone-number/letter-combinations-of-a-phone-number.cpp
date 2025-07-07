/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<char,string>keypad = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    void backtrack(string &digits,int indx,string &subString, vector<string>&result){
        if(indx == digits.size()){
            result.push_back(subString);
            return;
        }
        for(char ch : keypad[digits[indx]]){
            subString.push_back(ch);
            backtrack(digits,indx+1,subString,result);
            subString.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.size()<1)return result;
        string subString = "";
        backtrack(digits,0,subString,result);
        return result;
    }
};
// @lc code=end

