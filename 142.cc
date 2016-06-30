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
    ListNode *detectCycle(ListNode *head) {
      unordered_map<ListNode*, bool> mymap;
      ListNode* ptr = head;
      while (ptr){
        if (mymap.find(ptr) == mymap.end())
          mymap[ptr] = true;
        else return ptr;
        ptr = ptr->next;
      }
      return NULL;
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
    ListNode *detectCycle(ListNode *head) {
      if( !head || head -> next == NULL )
        return NULL;
      ListNode *slow = head, *fast = head;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
          break;
      }
      if (fast != slow)
        return NULL;
      while (head != slow) {
        slow = slow->next;
        head = head->next;
      }
      return head;
    }
};
