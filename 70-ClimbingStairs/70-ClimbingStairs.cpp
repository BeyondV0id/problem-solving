// Last updated: 4/6/2025, 7:04:15 PM
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev1 = 2, prev2 = 1, curr;
        
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;  // Fibonacci relation
            prev2 = prev1;
            prev1 = curr;
        }
        
        return curr;
    }
};