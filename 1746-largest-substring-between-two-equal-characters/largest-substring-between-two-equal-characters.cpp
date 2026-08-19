
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> getIndx;
        int maxLen = -1;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (getIndx.count(ch)) {
                int l = getIndx[ch];
                maxLen = max(maxLen, i - l - 1);
            }
            else{
                getIndx[ch] = i;
            }
        }
        return maxLen;
    }
};
