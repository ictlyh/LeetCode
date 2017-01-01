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
    ListNode* swapPairs(ListNode* head) {
      ListNode* dummy = new ListNode(-1);
      dummy->next = head;
      ListNode* ptr = dummy;
      while (head && head->next) {
        ListNode* tmp = head->next->next;
        ptr->next = head->next;
        head->next->next = head;
        head->next = tmp;
        ptr = head;
        head = tmp;
      }
      return dummy->next;
    }
};
