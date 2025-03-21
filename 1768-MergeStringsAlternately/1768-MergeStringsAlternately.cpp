// Last updated: 3/21/2025, 6:55:34 PM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        int n = min(n1, n2);
        string ans = "";
        for(int i=0; i<n; i++) {
            ans += word1[i];
            ans += word2[i];
        }
        if(n1>n2) ans += word1.substr(n, n1-n);
        else if(n2>n1) ans += word2.substr(n, n2-n);
        return ans;
    }
};