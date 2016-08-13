class Solution {
  public:
    ListNode* ReverseList(ListNode* pHead) {
      ListNode* dummy = new ListNode(-1);
      while (pHead) {
        ListNode* tmp = pHead->next;
        pHead->next = dummy->next;
        dummy->next = pHead;
        pHead = tmp;
      }
      return dummy->next;
    }
};
