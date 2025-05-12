class Solution {
private:
    unordered_set<int> isUnique;
    bool isValid(int x) { return (x % 2 == 0); }

public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == j || k == i)
                        continue;
                    int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (isValid(number) && !isUnique.count(number)) {
                        isUnique.insert(number);
                        res.push_back(number);
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};