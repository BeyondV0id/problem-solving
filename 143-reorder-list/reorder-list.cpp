// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        ListNode* a = NULL;
        ListNode* c = slowPtr->next;
        slowPtr->next = nullptr;
        ListNode* b = NULL;
        while (c != NULL) {
            a = b;
            b = c;
            c = c->next;
            b->next = a;
        }
        fastPtr = b;
        ListNode* first = head;
        while (fastPtr && first) {
            ListNode* t1 = first->next;
            ListNode* t2 = fastPtr->next;

            first->next = fastPtr;
            fastPtr->next = t1;
            first = t1;
            fastPtr = t2;
        }
    }
};
// @leet end
