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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next == nullptr)return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevOfslow = nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prevOfslow = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prevOfslow->next = slow->next;
        delete slow;
        return head;
        

        
        
    }
};