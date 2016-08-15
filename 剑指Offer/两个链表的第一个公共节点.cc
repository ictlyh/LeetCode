class Solution {
  public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
      int list1len = 0;
      ListNode* ptr1 = pHead1;
      while (ptr1) {
        list1len++;
        ptr1 = ptr1->next;
      }
      int list2len = 0;
      ListNode* ptr2 = pHead2;
      while (ptr2) {
        list2len++;
        ptr2 = ptr2->next;
      }
      ptr1 = pHead1;
      ptr2 = pHead2;
      while (list1len > list2len) {
        ptr1 = ptr1->next;
        list1len--;
      }
      while (list2len > list1len) {
        ptr2 = ptr2->next;
        list2len--;
      }
      while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
      }
      return ptr1;
    }
};
