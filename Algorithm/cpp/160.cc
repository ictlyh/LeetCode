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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (!headA || !headB) return NULL;
      unordered_map<ListNode*, bool> mymap;
      ListNode* cur = headA;
      while (cur) {
        if (mymap.find(cur) == mymap.end())
          mymap[cur] = true;
        cur = cur->next;
      }
      cur = headB;
      while (cur) {
        if (mymap.find(cur) != mymap.end()) return cur;
        cur = cur->next;
      }
      return NULL;
    }
};

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int A_length = length_ListNode(headA);
      int B_length = length_ListNode(headB);
      if(A_length!=B_length)
      {
        if(A_length>B_length)
        {
          while(A_length!=B_length)
          {
            headA = headA->next;
            A_length--;
          }
        }
        else{
          while(A_length!=B_length)
          {
            headB = headB->next;
            B_length--;
          }
        }
      }
      while(headA!=headB && headA!=NULL)
      {
        headA=headA->next;
        headB = headB->next;
      }
      return headA;
    }
    int length_ListNode(ListNode* head)
    {
      ListNode* temp = head;
      int length=0;
      while(temp){
        length++;
        temp = temp->next;
      }
      return length;
    }
};
