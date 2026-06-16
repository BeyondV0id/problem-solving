class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;

        for (auto head : lists) {
            while (head) {
                vals.push_back(head->val);
                head = head->next;
            }
        }

        sort(vals.begin(), vals.end());

        if (vals.empty())
            return nullptr;

        ListNode* head = new ListNode(vals[0]);
        ListNode* curr = head;

        for (int i = 1; i < vals.size(); i++) {
            curr->next = new ListNode(vals[i]);
            curr = curr->next;
        }

        return head;
    }
};