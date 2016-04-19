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
		ListNode* oddEvenList(ListNode* head) {
			if (!head || !head->next || !head->next->next) return head;
			ListNode* odd_tail = head;
			ListNode* even_head = head->next;
			ListNode* even_tail = head->next;
			ListNode* cur = head->next->next;
			bool odd = true;
			while (cur) {
				if (odd){
					odd_tail->next = cur;
					odd_tail = cur;
					odd = false;
				} else {
					even_tail->next = cur;
					even_tail = cur;
					odd = true;
				}
				cur = cur->next;
			}
			odd_tail->next = even_head;
			even_tail->next = NULL;
			return head;
		}
};
