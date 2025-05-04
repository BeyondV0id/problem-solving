class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        int n = word.size();
        for (auto& ch : word)
            freq[ch]++;
        for (auto& ch : word) {
            freq[ch]--;
            if (freq[ch] == 0)
                freq.erase(ch);
            unordered_set<int> check;
            for (auto& it : freq)
                check.insert(it.second);
            if (check.size() == 1)
                return true;
            freq[ch]++;
        }
        return false;
    }
};