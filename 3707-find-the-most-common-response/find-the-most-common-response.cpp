class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        bool sameArray = true;
        int n = responses.size();

        unordered_map<string, int> freq;

        for (int i = 0; i < n; i++) {
            unordered_map<string, bool> seenToday;
            for (int j = 0; j < responses[i].size(); j++) {

                string message = responses[i][j];

                if (!seenToday.count(message)) {
                    freq[message]++;
                    seenToday[message] = true;
                }
            }
        }
        string ans = "";
        int maxfreq = 0;
        for (auto& it : freq) {
            if (it.second > maxfreq) {
                ans = it.first;
                maxfreq = it.second;
            } else if (it.second == maxfreq)
                ans = min(ans, it.first);
        }
        return ans;
    }
};