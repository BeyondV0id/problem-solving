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
    ListNode* rotateRight(ListNode* head, int k) {
       if (!head || !head->next || k == 0) return head;
       ListNode* temp = head;
       int size = 1;
       temp = head;
       while(temp->next!=nullptr){
        temp = temp->next;
        size++; 
        }
        k = k%size;
        if(k==0)return head;
        int lastIndex = size-k;
        ListNode* temp2 = head;
        for(int i=1;i<lastIndex;i++){
            temp2=temp2->next;
        }
        ListNode *newNode = temp2->next;
        temp2->next = nullptr;
        temp->next = head;

        
        return newNode;   
    }
};