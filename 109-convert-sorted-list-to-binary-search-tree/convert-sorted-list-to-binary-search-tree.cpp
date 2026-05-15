class Solution {
private:
    TreeNode* generateBST(vector<int>& list, int left, int right) {

        if (left > right)
            return nullptr;

        int mid = (left + right) / 2;

        TreeNode* node = new TreeNode(list[mid]);

        node->left = generateBST(list, left, mid - 1);
        node->right = generateBST(list, mid + 1, right);

        return node;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int> list;

        ListNode* temp = head;

        while (temp != nullptr) {
            list.push_back(temp->val);
            temp = temp->next;
        }

        return generateBST(list, 0, list.size() - 1);
    }
};