class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto words : knowledge) {
            mp[words[0]] = words[1];
        }

        string res = "";
        string t = "";
        bool f = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                f = true;
            }
            else if (s[i] == ')') {
                if (mp.count(t))
                    res += mp[t];
                else
                    res += "?";

                t = "";
                f = false;
            }
            else {
                if (f)
                    t += s[i];
                else
                    res += s[i];
            }
        }

        return res;
    }
};