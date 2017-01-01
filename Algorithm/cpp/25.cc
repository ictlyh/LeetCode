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

    ListNode* reverseKGroup(ListNode* head, int k) {
      if (!head || !head->next) return head;
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* ptr = dummy;
      ListNode* cur = head;
      while (true) {
        for (int i = 1; i < k; i++) {
          if (cur) cur = cur->next;
          else break;
        }
        if (cur) {
          ListNode* tmp = cur->next;
          cur->next = NULL;
          ptr->next = reverseList(head);
          ptr = head;
          head = tmp;
          cur = tmp;
        } else {
          ptr->next = head;
          break;
        }
      }
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
    ListNode* revertList(ListNode* head, ListNode** newHead) {
      if (!head) return head;
      if (head->next) {
        ListNode* tail = revertList(head->next, newHead);
        tail->next = head;
        head->next = NULL;
      }
      else *newHead = head;
      return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
      if (!head || !head->next) return head;
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* tail = dummy;
      ListNode* newHead = new ListNode(0);
      ListNode* cur = head;
      while (true) {
        for (int i = 1; i < k; i++) {
          if (cur) cur = cur->next;
          else break;
        }
        if (cur) {
          ListNode* tmp = cur->next;
          cur->next = NULL;
          ListNode* tmpTail = revertList(head, &newHead);
          tail->next = newHead;
          tail = tmpTail;
          head = tmp;
          cur = tmp;
        } else {
          tail->next = head;
          break;
        }
      }
      return dummy->next;
    }
};
