// Last updated: 4/24/2025, 5:10:46 AM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = 0;
        int l = 0;
        unordered_map<int,int> seen;
        int maxLen = 0;

        for (int r = 0; r < fruits.size(); r++) {
            seen[fruits[r]]++;
            while (seen.size() > 2) {
                seen[fruits[l]]--;
                if(seen[fruits[l]] == 0)
                    seen.erase(fruits[l]);
                l++;
            }
            maxLen = max(maxLen, (r-l)+1);
        }
        return maxLen;
    }
};