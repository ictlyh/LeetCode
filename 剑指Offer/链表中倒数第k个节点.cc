class Solution {
  public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      ListNode* ptr = pListHead;
      while (ptr && k) {
        k--;
        ptr = ptr->next;
      }
      if (k) return NULL;
      ListNode* cur = pListHead;
      while (ptr) {
        ptr = ptr->next;
        cur = cur->next;
      }
      return cur;
    }
};
