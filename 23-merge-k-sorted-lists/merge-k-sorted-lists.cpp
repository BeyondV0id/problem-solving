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

        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int x : vals) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy.next;
    }
};