class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int indx = 0; indx < n; indx++) {
            if (words[indx] == target) {
                int dist = abs(indx - startIndex);
                dist = min(dist, n - dist);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};