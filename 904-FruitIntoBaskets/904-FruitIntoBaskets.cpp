// Last updated: 4/24/2025, 5:11:14 AM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0,maxLen=0;
        unordered_map<int,int> mp;
        while(r<n) {
            mp[fruits[r]]++;
            while(mp.size()>2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            int len=r-l+1;
            maxLen=max(len,maxLen);
            r++;
        }
        return maxLen;
    }
};