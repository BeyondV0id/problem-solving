#include <unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int cnt = 0;

        for (auto stone : stones) {
            if (jewelSet.count(stone)) {
                cnt++;
            }
        }

        return cnt;
    }
};
