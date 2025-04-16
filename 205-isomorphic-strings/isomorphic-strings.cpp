class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> s_t;
        unordered_map<char, char> t_s;
        for (int i = 0; i < s.size(); i++) {
            char sChar = s[i];
            char tChar = t[i];
            if (s_t.count(sChar) && s_t[sChar] != tChar)
                return false;
            else if (t_s.count(tChar) && t_s[tChar] != sChar)
                return false;
            s_t[sChar] = tChar;
            t_s[tChar] = sChar;
        }
        return true;
    }
};