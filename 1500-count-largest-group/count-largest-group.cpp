class Solution {
private:
    int find_digit_Sum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {
        int maxval = 0;
        int cnt = 0;
        unordered_map<int, int> grps;
        for (int i = 1; i <= n; i++) {
            int sum = find_digit_Sum(i);
            grps[sum]++;
            if (grps[sum] > maxval) {
                maxval = grps[sum];
                cnt = 1;
            }
            else if (grps[sum] == maxval) 
                    cnt++;
            }return cnt;
        }
};