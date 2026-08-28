// @leet imports start
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
// @leet imports end

// @leet start
class Solution {
private:
    bool allocate_books(int limit, vector<int>& books, int students) {
        int cnt = 1;
        int curPages = 0;

        for (int i = 0; i < (int)books.size(); i++) {
            int pages = books[i];
            if (curPages + pages <= limit) {
                curPages += pages;
            } else {
                cnt++;
                curPages = pages; // assing outof limit book to new student
                if (cnt > students) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k)
            return -1;

        int ans = -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (allocate_books(mid, nums, k)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
// @leet end
