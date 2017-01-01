/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      unordered_map<RandomListNode*, RandomListNode*> mymap;
      RandomListNode* dummy =  new RandomListNode(-1);
      RandomListNode *oldptr = head;
      RandomListNode *newptr = dummy;
      while (oldptr != NULL) {
        newptr->next = new RandomListNode(oldptr->label);
        mymap[oldptr] = newptr->next;
        oldptr = oldptr->next;
        newptr = newptr->next;
      }
      oldptr = head;
      newptr = dummy->next;
      while (oldptr != NULL) {
        newptr->random = mymap[oldptr->random];
        oldptr = oldptr->next;
        newptr = newptr->next;
      }
      return dummy->next;
    }
};
