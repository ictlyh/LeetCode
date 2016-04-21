

// Time Limit Exceeded
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
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if (lists.size() == 0) return NULL;
			if (lists.size() == 1) return lists[1];
			ListNode* head = lists[1];
			for (int i = 1; i < lists.size(); i++)
				head = mergeTwoLists(head, lists[i]);
			return head;
		}
};
