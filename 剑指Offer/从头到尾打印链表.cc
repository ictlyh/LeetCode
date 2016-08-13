/**
 *  struct ListNode {
 *        int val;
 *        struct ListNode *next;
 *        ListNode(int x) :
 *              val(x), next(NULL) {
 *        }
 *  };
 */
class Solution {
  public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
      if (head == NULL) return vector<int>();
      vector<int> res = printListFromTailToHead(head->next);
      res.push_back(head->val);
      return res;
    }
};
class Solution {
  public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
      vector<int> res;
      ListNode* ptr = head;
      while (ptr) {
        res.push_back(ptr->val);
        ptr = ptr->next;
      }
      return vector<int>(res.rbegin(), res.rend());
    }
};
