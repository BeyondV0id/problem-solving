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
        unordered_map<int, int> grps;
        for (int i = 1; i <= n; i++) {
            int sum = find_digit_Sum(i);
            grps[sum]++;
        }
        int maxVal = 1;
        for (auto num : grps) {
            if (num.second > maxVal) {
                maxVal = num.second;
            }
        }
        int cnt = 0;
        for (auto num : grps) {
            if (num.second == maxVal) {
                cnt++;
            }
        }
        return cnt;
    }
};