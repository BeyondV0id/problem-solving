// Last updated: 3/24/2025, 5:11:37 PM
class Solution {
private:
     int reverse(int n){
        int rev = 0;
        while(n>0){
        int rem = n%10;
        rev = rev*10 + rem;
        n = n/10;
        }
        return rev;
        
     }
public:
    bool isSameAfterReversals(int num) {
        return num==reverse(reverse(num));
        
    }
};