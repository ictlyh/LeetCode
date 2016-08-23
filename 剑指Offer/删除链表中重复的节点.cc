class Solution {
  public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
      ListNode* dummy = new ListNode(-1);
      dummy->next = pHead;
      ListNode* ptr = dummy;
      while (ptr->next && ptr->next->next) {
        if (ptr->next->val == ptr->next->next->val) {
          ListNode* todelete = ptr->next->next;
          while (todelete->next && todelete->val == todelete->next->val)
            todelete = todelete->next;
          ptr->next = todelete->next;
        } else ptr = ptr->next;
      }
      return dummy->next;
    }
};
