class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxxi = -1;
        unordered_map<int,int>freq;
        for(auto &it : arr)
            freq[it]++;
        for(auto &it : freq){
            if(it.second == it.first)
                maxxi = max(maxxi,it.first);
        }
        return maxxi;
   }
};