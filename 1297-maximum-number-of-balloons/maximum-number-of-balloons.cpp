class Solution {
public:
    int maxNumberOfBalloons(string text) {

        vector<int> freq(26, 0);

        for (char ch : text)
            freq[ch - 'a']++;

        int ans = 0;

        while (true) {

            if (freq['b' - 'a'] < 1) break;
            if (freq['a' - 'a'] < 1) break;
            if (freq['l' - 'a'] < 2) break;
            if (freq['o' - 'a'] < 2) break;
            if (freq['n' - 'a'] < 1) break;

            freq['b' - 'a']--;
            freq['a' - 'a']--;
            freq['l' - 'a'] -= 2;
            freq['o' - 'a'] -= 2;
            freq['n' - 'a']--;

            ans++;
        }

        return ans;
    }
};