// Last updated: 4/3/2025, 6:45:40 PM
class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            freq[i]--;
            unordered_set<int> virat;
            for (int f : freq)
                if (f > 0)
                    virat.insert(f);
            if (virat.size() == 1)
                return true;

            freq[i]++;
        }
        return false;
    }
};