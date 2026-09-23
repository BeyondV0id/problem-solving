class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        // map number to {difference, valid}
        // initially store {index, 1}

        // if the number is seen for the first time.. store {index, 1}

        // if the number is seen for 2nd time, calculate and store diff

        // if the number is seen 3 or more times, compare the diff
        // if diff is different, mark it invalid

        unordered_map<int, pair<int, int>> store;

        unordered_map<int, int> lastIndx;

        for (int i = 0; i < nums.size(); i++) {

            int num = nums[i];

            if (!store.count(num)) {
                // First occurrence
                store[num] = {i, 1};
            }

            else if (store[num].second == 1) {
                // Second occurrence
                int diff = i - store[num].first;

                store[num].first = diff;
                store[num].second = 2;
            }

            else {
                int diff = i - lastIndx[num];

                if (diff != store[num].first) {
                    // fuck the number
                    store[num].second = -1;
                } else {
                    store[num].second++;
                }
            }

            lastIndx[num] = i;
        }

        int ans = 0;

        for (auto m : store) {
            if (m.second.second >= 3) {
                ans++;
            }
        }

        return ans;
    }
};