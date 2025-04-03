// Last updated: 4/3/2025, 6:49:33 PM
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
            unordered_set<int> freqSet;
            for (int f : freq)
                if (f > 0)
                    freqSet.insert(f);
            bool allSameFreq = (freqSet.size() == 1);
            if (allSameFreq)
                return true;
            freq[i]++;
        }
        return false;
    }
};