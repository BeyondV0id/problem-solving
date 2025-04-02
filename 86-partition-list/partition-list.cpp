/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesserHeader = new ListNode();
        ListNode* greaterHeader = new ListNode();
        ListNode* greater = greaterHeader;
        ListNode* lesser = lesserHeader;
        while(head){
            if(head->val<x){
                lesser->next = head;
                lesser = lesser->next;
            }
            else{
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        greater->next = nullptr;
        lesser->next = greaterHeader->next;
        return lesserHeader->next;

        
        
    }
};
// @lc code=end

