// Last updated: 4/27/2025, 5:17:00 PM
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int size = 10;
        int n = s.size();
        vector<string> result;
        unordered_set<string> seen;
        unordered_set<string> unique;
        seen.insert(s.substr(0, 10));
        for (int i = 1; i <= n - size; i++) {

            string subs = s.substr(i, size);
            if (seen.count(subs)) {
                unique.insert(subs);

            } else {
                seen.insert(subs);
            }
        }
        for (const auto& it : unique) {
            result.push_back(it);
        }
        return result;
    }
};
// @lc code=end
