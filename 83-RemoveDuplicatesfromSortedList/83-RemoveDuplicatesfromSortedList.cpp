// Last updated: 4/27/2025, 5:38:09 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* left = head;
        ListNode* right = head->next;
        while (right != nullptr) {
            if (right->val != left->val) {
                left->next = right;
                left = left->next;
            }
            right = right->next;
        }
        left->next = nullptr;

        return head;
    }
};