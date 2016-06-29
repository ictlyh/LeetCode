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
    bool isPalindrome(ListNode* head) {
      ListNode* fast = head;
      ListNode* slow = head;

      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
      }

      if(fast != nullptr) slow = slow->next;

      slow = reverseList(slow);

      fast = head;
      while(slow != nullptr){
        if(fast->val != slow->val) return false;
        fast = fast->next;
        slow = slow->next;
      }

      return true;
    }

    ListNode* reverseList(ListNode* head){
      if(head == nullptr || head->next == nullptr) return head;

      ListNode* node = reverseList(head->next);
      head->next->next = head;
      head->next = nullptr;

      return node;
    }
};
