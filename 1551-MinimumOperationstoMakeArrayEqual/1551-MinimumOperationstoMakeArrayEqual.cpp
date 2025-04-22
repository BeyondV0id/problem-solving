// Last updated: 4/22/2025, 7:05:55 PM
class Solution {
public:
    int minOperations(int n) {
        /* for(int i=0;i<n;i++){
             cout<<(2 * i) + 1<<" ";*/
        int cnt = 0;
        int target = n;
        for (int i = 0; i < n / 2; i++) {
            cnt += target - (2 * i + 1);
        }
        return cnt;
    }
}

;