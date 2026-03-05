class Solution {
private:
    vector<int>arr;
public:
    Solution(ListNode* head) {
      while(head){
        arr.push_back(head->val);
        head = head->next;
      }
    }
    
    int getRandom() {
      return arr[rand() % arr.size()];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */