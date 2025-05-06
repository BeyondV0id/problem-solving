class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int windowSize = s1.size();
        if (windowSize > n)
            return false;
        unordered_map<char, int> s1map;
        unordered_map<char, int> windowMap;
        for (auto& c : s1) {
            s1map[c]++;
        }
        int l = 0, r = 0;
        while (r < n) {
            windowMap[s2[r]]++;
            if (windowSize == r - l + 1) {
                if (windowMap == s1map) return true;
                windowMap[s2[l]]--;
                if (windowMap[s2[l]] == 0) windowMap.erase(s2[l]);
                l++;
            }
            r++;
        }
        return false;
    }
};