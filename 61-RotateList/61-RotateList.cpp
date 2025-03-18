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
        //point temp to last node
        k = k%size;//check to mod size
        if(k==0)return head;
        int lastIndex = size-k;//get index where last element would be after rotation..
        ListNode* temp2 = head;
        for(int i=1;i<lastIndex;i++){
            temp2=temp2->next;
        }
        //temp2 points to the node that would be new last node
        ListNode *newHead = temp2->next;//newHead will point to next index of temp2
        temp2->next = nullptr;//make temp2 null as it is last
        temp->next = head;//dont forget to connect temp(last node of normal list) to head of normal linked list


        return newHead;   
    }
};