class Solution {
public:
    bool isHappy(int n) {
        if (n == 1)
            return true;
        int slow, fast;
        slow = n;
        fast = sumSquares(n);
        while (fast != 1 && slow != fast) {
            slow = sumSquares(slow);
            fast = sumSquares(sumSquares(fast));
        }
        return fast==1;
    }
    int sumSquares(int n) {
        if (n == 1)
            return 1;
        int sumOfSquares = 0;
        while (n > 0) {
            int rem = n % 10;
            sumOfSquares += rem * rem;
            n = n / 10;
        }
        cout << sumOfSquares << endl;
        return sumOfSquares;
    }
};