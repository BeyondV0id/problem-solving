class Solution {
private:
    int INF = 1e9;
    int search(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int l = start;
        int r = n - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }

        if (nums[l] != target)
            return -1;

        return l;
    }

public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> prefix(n + 1, 0);

        int ans = INF;

        vector<int> best(n + 1, INF);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        for (int i = 0; i < n; i++) {
            // target = prefix[j + 1] - prefix[i] -> arr[i....j]

            int find = prefix[i] + target; // j + 1
            int indx = search(prefix, find, i + 1);
            if (indx != -1) {

                int len = indx - i;

                if (best[i] != INF)
                    ans = min(ans, len + best[i]);

                best[indx] = min(best[indx], len);
            }
            best[i + 1] = min(best[i + 1], best[i]);
        }
        return ans == INF? - 1 : ans;
    }
};