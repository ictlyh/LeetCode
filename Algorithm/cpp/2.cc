/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummy = new ListNode(-1);
      ListNode* ptr = dummy;
      int carry = 0;
      while (l1 || l2) {
        int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ptr->next = new ListNode(sum % 10);
        ptr = ptr->next;
        carry = sum / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
      }
      if (carry) ptr->next = new ListNode(1);
      return dummy->next;
    }
};
