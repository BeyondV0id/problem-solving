class Solution {
private:
    int getMaxFreqNum(unordered_map<int, int>& freqMap) {
        int maxfreq = 0;
        int num = -1;
        for (auto& it : freqMap) {
            if (it.second > maxfreq) {
                maxfreq = it.second;
                num = it.first;
            }
        }
        return num;
    }

    int minRotations(vector<int>& tops, vector<int>& bottoms, int target) {
        int n = tops.size();
        int mintoprotate = 0;
        int minbotrotate = 0;

        for (int i = 0; i < n; i++) {
            if (tops[i] != target && bottoms[i] != target)
                return -1;
            else if (tops[i] != target)
                mintoprotate++;
            else if (bottoms[i] != target)
                minbotrotate++;
        }
        return min(mintoprotate, minbotrotate);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> topfreq, botfreq;
        int n = tops.size();

        for (int i = 0; i < n; i++) {
            topfreq[tops[i]]++;
            botfreq[bottoms[i]]++;
        }

        int toptarget = getMaxFreqNum(topfreq);
        int bottomtarget = getMaxFreqNum(botfreq);

        int rot1 = minRotations(tops, bottoms, toptarget);
        int rot2 = minRotations(tops, bottoms, bottomtarget);

        if (rot1 == -1 && rot2 == -1) return -1;
        if (rot1 == -1) return rot2;
        if (rot2 == -1) return rot1;
        return min(rot1, rot2);
    }
};
