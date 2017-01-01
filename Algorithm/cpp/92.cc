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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode *leftI = dummy;
      for (; --m; --n) leftI = leftI->next;

      ListNode *cur = leftI->next, *rtail = cur, *pre = NULL;
      while (n--){
        ListNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
      }
      rtail->next = cur; leftI->next = pre;

      return dummy->next;
    }
};
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
    ListNode* reverseList(ListNode* head) {
      ListNode* dummy = new ListNode(-1);
      while (head) {
        ListNode* tmp = head->next;
        head->next = dummy->next;
        dummy->next = head;
        head = tmp;
      }
      return dummy->next;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* ptr = dummy;
      for (int i = 1; i < m; i++)
        ptr = ptr->next;
      ListNode* tail = ptr;
      for (int i = m; i <= n; i++) {
        tail = tail->next;
      }
      ListNode* rest = tail->next;
      tail->next = NULL;
      tail = ptr->next;
      ptr->next = reverseList(ptr->next);
      tail->next = rest;
      return dummy->next;
    }
};
