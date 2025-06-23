#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(auto &word : words)
            freq[word]++;
        auto compare = [&](const string& a,const string& b){
            if(freq[a] == freq[b])
                return a<b;
            return freq[a]>freq[b];
        };
        priority_queue<string,vector<string>,decltype(compare)>pq(compare);
        for(auto &it : freq){
            pq.push(it.first);
            if(pq.size()>k)
                pq.pop();
        }
        vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;

        
    }
};
// @lc code=end

