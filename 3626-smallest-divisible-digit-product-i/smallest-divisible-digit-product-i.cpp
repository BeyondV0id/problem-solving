class Solution {
private:
    bool isDiv(int n, int t){
        int p = 1;
        while(n > 0){
            int d = n % 10;
            p *= d;
            n = n / 10;
        }
        return p % t == 0;
    }
public:
    int smallestNumber(int n, int t) {
        
        for(int i = n; i <= 100; i++){
            if(isDiv(i,t))return i;
        }
        return -1;
    }
};