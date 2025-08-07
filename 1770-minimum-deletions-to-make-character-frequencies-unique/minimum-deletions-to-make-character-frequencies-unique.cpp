#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        int minOps = 0;
        unordered_map<char, int> freq;
        unordered_set<int> freq_uniqe_set;
        for (auto& it : s) {
            freq[it]++;
        }
        for (auto& [ch, cnt] : freq) {
            while (cnt > 0 && freq_uniqe_set.count(cnt)) {
                cnt--;
                minOps++;
            }
            if (cnt > 0)
                freq_uniqe_set.insert(cnt);
        }
        return minOps;
    }
};
