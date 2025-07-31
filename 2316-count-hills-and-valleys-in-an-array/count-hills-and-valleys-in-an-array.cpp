#include <vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& land) {
        int index = 1;
        for (int i = 1; i < land.size(); i++) {
            if (land[i] != land[i - 1]) {
                land[index++] = land[i];
            }
        }
        land.resize(index);

        int hillCnt = 0, valleyCnt = 0;
        int n = land.size();
        for (int i = 1; i < n - 1; i++) {
            bool isHill = false;
            bool isValley = false;

            if (land[i] > land[i - 1] && land[i] > land[i + 1])
                isHill = true;
            else if (land[i] < land[i - 1] && land[i] < land[i + 1])
                isValley = true;

            if (isHill)
                hillCnt++;
            else if (isValley)
                valleyCnt++;
        }

        return hillCnt + valleyCnt;
    }
};
