// Last updated: 3/28/2025, 4:07:03 PM
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool isSub = false;
        int cnt = 0;
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j] && i < s.size() && j < t.size()) {
                i++;
                j++;
                cnt++;
            } else {
                while(s[i] != t[j] && j < t.size()) {
                    j++;
                }
            }
        }
        return cnt == s.size();
    }
};