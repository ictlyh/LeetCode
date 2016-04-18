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
