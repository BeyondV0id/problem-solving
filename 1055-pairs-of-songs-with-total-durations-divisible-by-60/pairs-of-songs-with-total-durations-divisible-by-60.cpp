class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int M = 60;
        unordered_map<int, int> freq;

        for (int x : time) {
            int rem = x % M;
            freq[rem]++;
        }

        long long cnt = 0;

        // Remainder 0 pairs with remainder 0
        cnt += 1LL * freq[0] * (freq[0] - 1) / 2;

        for (int r = 1; r <= M / 2; r++) {

            // M/2 pairs with itself
            if (2 * r == M) {
                cnt += 1LL * freq[r] * (freq[r] - 1) / 2;
            } 
            else {
                // r pairs with M-r
                cnt += 1LL * freq[r] * freq[M - r];
            }
        }

        return (int)cnt;
    }
};