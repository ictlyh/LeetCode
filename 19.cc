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
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode* begin = head;
			ListNode* end = head;
			for (int i = 1; i <= n; i++) {
				if (!begin) return head;
				begin = begin ->next;
			}
			if (begin == NULL)
				return head->next;
			while (begin->next) {
				begin = begin->next;
				end = end->next;
			}
			end->next = end->next->next;
			return head;
		}
};
