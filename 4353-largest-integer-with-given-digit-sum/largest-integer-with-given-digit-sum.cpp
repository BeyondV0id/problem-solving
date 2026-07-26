class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int largestInteger(int n, int s) {

        if (s == 0)
            return 0;

        if (s > 9 * n)
            return -1;

        int limit = 1;
        for (int i = 0; i < n; i++)
            limit *= 10;

        limit--;

        for (int num = limit; num >= 1; num--) {
            if (digitSum(num) == s)
                return num;
        }

        return -1;
    }
};