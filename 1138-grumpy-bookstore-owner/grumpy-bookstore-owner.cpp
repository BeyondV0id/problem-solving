class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxNo = INT_MIN;
        int n = grumpy.size();

        int l = 0, r = 0;
        int total = 0;

        while (r < n) {
            if (grumpy[r] == 1)
                total += customers[r];

            while (r - l + 1 > minutes) {
                if (grumpy[l] == 1)
                    total -= customers[l];
                l++;
            }

            maxNo = max(maxNo, total);
            r++;
        }

        int alreadySatisfied = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                alreadySatisfied += customers[i];
        }

        return alreadySatisfied + maxNo;
    }
};