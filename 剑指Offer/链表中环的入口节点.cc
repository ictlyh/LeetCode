/*
   struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) :
   val(x), next(NULL) {
   }
   };
   */
class Solution {
  public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
      ListNode* slow = pHead;
      ListNode* fast = pHead;
      while (true) {
        if (fast == NULL || fast->next == NULL) return NULL;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
      }
      slow = pHead;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
};
