// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start


class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        while (head && st.count(head->val)) {
            head = head->next;
        }

        ListNode *temp = head;
        ListNode *prev = head;

        while (temp) {
            if (st.count(temp->val)) {
                prev->next = temp->next;
                temp = temp->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};
// @leet end