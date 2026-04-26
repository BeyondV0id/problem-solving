class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int numCookies = s.size();
        int childs = g.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        
        int l = 0, r = 0;
        int cnt = 0;
        
        while(l < numCookies && r < childs){
            if(g[r] <= s[l]){
                cnt++;
                l++;
                r++;
            }
            else{
                l++;
            }
        }
        return cnt;
    }
};