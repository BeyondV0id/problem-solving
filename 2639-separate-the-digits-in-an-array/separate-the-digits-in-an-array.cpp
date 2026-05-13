class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;

        for (int num : nums) {
            vector<int> t;

            while (num > 0) {
                t.push_back(num % 10);
                num /= 10;
            }

            reverse(t.begin(), t.end());

            for (int dig : t) {
                res.push_back(dig);
            }
        }

        return res;
    }
};