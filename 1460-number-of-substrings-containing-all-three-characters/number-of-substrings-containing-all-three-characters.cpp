class Solution {
public:
    int numberOfSubstrings(string s) {

        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        int n = s.size();
        int cnt = 0;

        // a b b a a b c c a b c

        while (r < n) {
            mp[s[r]]++;
            while (mp.size() == 3) {
                cnt += n - r;
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return cnt;
    }
};