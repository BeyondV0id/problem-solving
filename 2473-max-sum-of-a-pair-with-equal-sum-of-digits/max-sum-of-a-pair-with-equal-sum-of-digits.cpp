class Solution {
private:
    int sumDigits(int a) {
        int sum = 0;
        while (a > 0) {
            sum += a % 10;
            a = a / 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int sum = -1;
        unordered_map<int, int> sumMap;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int digitSum = sumDigits(num);

            if (sumMap.count(digitSum)) {
                int newSum = num + sumMap[digitSum];
                sum = max(sum, newSum);
                sumMap[digitSum] = max(sumMap[digitSum], num);
            } else {
                sumMap[digitSum] = num;
            }
        }
        return sum;
    }
};
