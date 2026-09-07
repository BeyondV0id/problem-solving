class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> lastOcur;
        for (int i = 0; i < n; i++)
            lastOcur[s[i]] = i;
        vector<int> ans;
        int maxi = -1;
        int prevIdx = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, lastOcur[s[i]]);
            if (maxi == i) {
                int len = maxi - prevIdx + 1;
                ans.push_back(len);
                prevIdx = maxi + 1;
                maxi = -1;
            }
        }
        return ans;
    }
};