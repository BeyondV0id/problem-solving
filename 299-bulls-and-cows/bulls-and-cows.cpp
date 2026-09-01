class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls = 0;
        int n = secret.size();

        unordered_set<int> flags;

        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                flags.insert(i);
            }
        }

        unordered_map<int, int> freq1;
        unordered_map<char, int> freq2;

        for (int i = 0; i < n; i++) {
            if (!flags.count(i)) {
                freq1[secret[i]]++;
                freq2[guess[i]]++;
            }
        }
        int cows = 0;

        for (auto& [ch, count] : freq1) {
            if (freq2.count(ch)) {
                cows += min(count, freq2[ch]);
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};