// Last updated: 4/29/2025, 4:12:13 PM
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>freq;
        int n = s.size();
        for(auto& c : s){
            freq[c]++;
        }
        int cnt = freq[s[0]];
        for(auto &it : freq){
            if(it.second!=cnt){
                return false;
            }
        }
        return true;
        
    }
};