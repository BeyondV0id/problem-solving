class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freqT(26, 0);
        int cnt = 0;

        for (int i = 0; i < target.size(); i++) {
            int ch = target[i] - 'a';
            freqT[ch]++;
        }

        vector<int> freqS(26, 0);

        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            freqS[ch]++;
        }

        while (true) {
            bool flag = true;

            for (int i = 0; i < 26; i++) {
                if (freqT[i] > 0 && freqS[i] < freqT[i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;

            for (int i = 0; i < 26; i++) {
                freqS[i] -= freqT[i];
            }

            cnt++;
        }

        return cnt;
    }
};