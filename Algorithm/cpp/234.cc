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
    bool isPalindrome(ListNode* head) {
      vector<ListNode*> nodes;
      ListNode* ptr = head;
      while (ptr != NULL) {
        nodes.push_back(ptr);
        ptr = ptr->next;
      }
      int left = 0;
      int right = nodes.size() - 1;
      while (left <= right) {
        if (nodes[left]->val != nodes[right]->val) return false;
        left++;
        right--;
      }
      return true;
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
    bool isPalindrome(ListNode* head) {
      if (!head || !head->next) return true;
      ListNode* slow = head;
      ListNode* fast = head->next;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      fast = reverseList(slow->next);
      slow->next = NULL;
      while (head && fast) {
        if (head->val != fast->val) return false;
        head = head->next;
        fast = fast->next;
      }
      return true;
    }
};
