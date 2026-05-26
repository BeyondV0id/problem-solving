// @leet imports start
#include <bits/stdc++.h>
#include <cctype>
using namespace std;
// @leet imports end
/// @leet start
class Solution {
  public:
    int numberOfSpecialChars(string word) {
      int n = word.size();
      unordered_set<int>invalid;
      unordered_map<char,int>lower;
      unordered_set<char>upper;


      for(int i = 0;i < n; i++){
        char ch = word[i];
        if(ch >= 'a' && ch <= 'z'){
          lower[ch] = i;
        }
      }

      for(int i = 0;i < n; i++){
        char ch = word[i];
        if(ch >= 'A' && ch <= 'Z'){
          char low = tolower(ch);
          if(lower.count(low)){
            int lowerIndx = lower[low];
            if(lowerIndx > i){
              invalid.insert(ch);
            }
            else{
              upper.insert(ch);
            }
          }
        }
      }
      int cnt = 0;

      for(auto ch : upper){
        if(!invalid.count(ch))
          cnt++;
      }
      return cnt;
    }
};
