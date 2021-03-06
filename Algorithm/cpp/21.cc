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
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (l1 == NULL) return l2;
			if (l2 == NULL) return l1;
			ListNode* head = new ListNode(0);
			ListNode* ptr = head;
			while (l1 && l2) {
				if (l1->val < l2->val) {
					ptr->next = l1;
					ptr = l1;
					l1 = l1->next;
				} else {
					ptr->next = l2;
					ptr = l2;
					l2 = l2->next;
				}
			}
			if (l1) ptr->next = l1;
			if (l2) ptr->next = l2;
			return head->next;
		}
};
