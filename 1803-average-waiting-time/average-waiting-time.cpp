// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
      int n = customers.size();
      double avgWaitingTime = 0;


      
      int currentTime = 0;
      int waitingTime = 0;
      for(int i = 0 ;i < n; i++){

        int startTime = customers[i][0];
        int finishTime = customers[i][1];

        if(currentTime > startTime){
          startTime = currentTime;
        }
        currentTime = startTime + finishTime;
        waitingTime = currentTime - customers[i][0];
        avgWaitingTime += waitingTime;
      }
      return avgWaitingTime/n;
        
    }
};
