#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>res;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        unordered_map<int,int>freq;
        for(auto & it: nums){
            minHeap.push(it);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        while(!minHeap.empty()){
            freq[minHeap.top()]++;
            minHeap.pop();
        }
        for(auto &it : nums){
            if(freq[it]>0){
                res.push_back(it);
                freq[it]--;
            }
        }
        return res;

        
    }
};
// @lc code=end

