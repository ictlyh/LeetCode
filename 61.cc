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
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head || !head->next) return head;
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* tail = dummy;
      int len = 0;
      while (head) {
        len++;
        tail = head;
        head = head->next;
      }
      k = k % len;
      if (k == 0) return dummy->next;
      head = dummy->next;
      k = len - k;
      while (--k) {
        head = head->next;
      }
      tail->next = dummy->next;
      dummy->next = head->next;
      head->next = NULL;
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
    int length(ListNode* head) {
      int len = 0;
      while (head) {
        len++;
        head = head->next;
      }
      return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
      int len = length(head);
      if (len == 0) return NULL;
      k = len - k % len;
      if (k == len) return head;
      ListNode* ptr = head;
      while (--k) ptr = ptr->next;
      ListNode* newHead = ptr->next;
      ptr->next = NULL;
      ptr = newHead;
      while (ptr->next) ptr = ptr->next;
      ptr->next = head;
      return newHead;
    }
};
