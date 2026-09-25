class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();

        vector<int> prefixN(n + 1, 0);
        vector<int> suffixY(n + 1, 0);

        // N in [0, i-1]
        for (int i = 1; i <= n; i++) {
            prefixN[i] = prefixN[i - 1] + (s[i - 1] == 'N' ? 1 : 0);
        }

        // Y in [i, n-1]
        for (int i = n - 1; i >= 0; i--) {
            suffixY[i] = suffixY[i + 1] + (s[i] == 'Y' ? 1 : 0);
        }

        int minPenalty = INT_MAX;
        int answer = 0;

        for (int j = 0; j <= n; j++) {
            int penalty = prefixN[j] + suffixY[j];

            if (penalty < minPenalty) {
                minPenalty = penalty;
                answer = j;
            }
        }

        return answer;
    }
};