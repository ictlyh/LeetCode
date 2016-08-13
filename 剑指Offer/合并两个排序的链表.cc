class Solution {
  public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
      ListNode* dummy = new ListNode(-1);
      ListNode* cur = dummy;
      while (pHead1 && pHead2) {
        if (pHead1->val < pHead2->val) {
          ListNode* tmp = pHead1->next;
          pHead1->next = cur->next;
          cur->next = pHead1;
          pHead1 = tmp;
        } else {
          ListNode* tmp = pHead2->next;
          pHead2->next = cur->next;
          cur->next = pHead2;
          pHead2 = tmp;
        }
        cur = cur->next;
      }
      if (pHead1) cur->next = pHead1;
      if (pHead2) cur->next = pHead2;
      return dummy->next;
    }
};
