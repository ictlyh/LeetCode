/*
   struct RandomListNode {
   int label;
   struct RandomListNode *next, *random;
   RandomListNode(int x) :
   label(x), next(NULL), random(NULL) {
   }
   };
   */
class Solution {
  public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
      if (!pHead) return NULL;
      RandomListNode* ptr = pHead;
      while (ptr) {
        RandomListNode* newNode = new RandomListNode(ptr->label);
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr = newNode->next;
      }
      ptr = pHead;
      while (ptr) {
        if (ptr->random) ptr->next->random = ptr->random->next;
        ptr = ptr->next->next;
      }
      RandomListNode* newHead = pHead->next;
      ptr = pHead;
      while (ptr) {
        RandomListNode* tmp = ptr->next->next;
        if (tmp) ptr->next->next = tmp->next;
        delete ptr;
        ptr = tmp;
      }
      return newHead;
    }
};
