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
		ListNode* partition(ListNode* head, int x) {
			if (!head || !head->next) return head;
			ListNode* less_head = new ListNode(0);
			ListNode* less_tail = less_head;
			ListNode* more_head = new ListNode(0);
			ListNode* more_tail = more_head;
			ListNode* cur = head;
			while (cur) {
				if (cur->val < x) {
					less_tail->next = cur;
					less_tail = cur;
				} else {
					more_tail->next = cur;
					more_tail = cur;
				}
				cur = cur->next;
			}
			less_tail->next = more_head->next;
			more_tail->next = NULL;
			return less_head->next;
		}
};
