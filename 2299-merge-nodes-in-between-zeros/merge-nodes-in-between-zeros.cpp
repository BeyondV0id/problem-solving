
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* res = ans;
        head = head->next;
        long long sum = 0;
        while (head) {
            if (head->val != 0) {
                sum += head->val;
            } else {
                res->val = sum;
                if (head->next) {
                    res->next = new ListNode();
                    res = res->next;
                    sum = 0;
                }
            }
            head = head->next;
        }
        return ans;
    }
};
