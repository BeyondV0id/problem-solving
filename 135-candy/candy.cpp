class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> child(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                child[i] = child[i - 1] + 1;
            }
        }

        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                child[i - 1] = max(child[i - 1], 1 + child[i]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += child[i];
        }
        return cnt;
    }
};