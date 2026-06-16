// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end
class Solution {
public:
    bool checkGoodInteger(int n) {
      vector<int>digits;
      string s = to_string(n);
      for(auto ch : s){
        digits.push_back(ch-'0');
      }
      int a = 0;
      int b = 0;
      for(int i = 0; i < (int)digits.size(); i++){
        a += digits[i];
        b += digits[i]*digits[i];
      }
      return b - a >= 50;
    }
};
