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
		ListNode* insertionSortList(ListNode* head) {
			if (head == NULL || head->next == NULL) return head;
			ListNode* cur = head;
			int minVal = head->val;
			ListNode* minPtr = head;
			ListNode* ptr;
			while (cur ->next) {
				minPtr = cur;
				minVal = cur->val;
				ptr = cur->next;
				while (ptr) {
					if (ptr->val < minVal) {
						minPtr = ptr;
						minVal = ptr->val;
					}
					ptr = ptr->next;
				}
				if (cur->val != minVal) {
					minPtr->val = cur->val;
					cur->val = minVal;
				}
				cur = cur->next;
			}
			return head;
		}
};
