// Solution 2
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
    ListNode* deleteDuplicates(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* cur = dummy;
      ListNode* pre = head->next;
      bool repeated = false;
      while (pre) {
        if (pre->val == head->val) {
          repeated = true;
          pre = pre->next;
        } else {
          if (repeated) {
            cur->next = pre;
            head = pre;
            pre = pre->next;
            repeated = false;
          } else {
            cur = head;
            head = pre;
            pre = pre->next;
            repeated = false;
          }
        }
      }
      if (repeated)
        cur->next = NULL;
      else {
        cur->next = head;
        head->next = NULL;
      }
      return dummy->next;
    }
};
class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode* dummy = new ListNode(-1);
      dummy->next = head;
      ListNode* ptr = dummy;
      while (ptr->next){
        ListNode *tmp = ptr->next;
        int current = tmp->val, count = 1;
        tmp = tmp->next;
        while (tmp && tmp->val == current){
          count++;
          tmp = tmp->next;
        }
        if (count > 1) ptr->next = tmp;
        else ptr = ptr->next;
      }
      return dummy->next;
    }
};
