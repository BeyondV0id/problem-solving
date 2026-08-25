class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {

        sort(special.begin(), special.end());

        int maxLen = 0;

        maxLen = special[0] - bottom;

        for (int i = 1; i < special.size(); i++) {

            int gap = special[i] - special[i - 1] - 1;

            maxLen = max(maxLen, gap);
        }

        maxLen = max(maxLen, top - special.back());

        return maxLen;
    }
};