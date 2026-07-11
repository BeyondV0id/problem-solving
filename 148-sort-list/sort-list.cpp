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
    ListNode* sortList(ListNode* head) {
        ListNode* dummy = head;
        vector<int>arr;

        while(dummy){
            arr.push_back(dummy->val);
            dummy = dummy->next;
        }
        sort(arr.begin(),arr.end());
        dummy = head;

        for(auto &it : arr){
            dummy->val = it;
            dummy = dummy->next;
        }

        return head;

        
        
    }
};