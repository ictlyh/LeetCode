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
		ListNode* removeElements(ListNode* head, int val) {
			while (head && head->val == val)
				head = head->next;
			if (head == NULL) return head;
			ListNode* end = head;
			ListNode* begin = head->next;
			while (begin) {
				if (begin->val == val)
					end->next = begin->next;
				else
					end = begin;
				begin = begin->next;
			}
			return head;
		}
};
