class Solution {
public:
    int beautySum(string s) {
        int cnt = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                int minFreq = INT_MAX;
                int maxFreq = INT_MIN;
                char ch = s[j];
                freq[ch]++;

                for (auto& it : freq) {
                    minFreq = min(it.second, minFreq);
                    maxFreq = max(it.second, maxFreq);
                }

                cnt += maxFreq - minFreq;
            }
        }
        return cnt;
    }
};