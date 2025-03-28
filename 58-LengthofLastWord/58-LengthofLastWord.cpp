// Last updated: 3/28/2025, 1:52:53 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size()-1;
        while(i>-1 && s[i] == ' '){
            i--;
        }
        while(i>-1 &&s[i]!=' '){
            len++;
            i--;
        }
        return len;

    }
};