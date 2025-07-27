#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int openCnt = 0;
        int maxLen = 0;

        for (auto& ch : s) {
            if (ch == '(') {
                openCnt++;
                maxLen = max(maxLen, openCnt);
            } else if (ch == ')') {
                openCnt--;
            }
        }

        return maxLen;
    }
};
