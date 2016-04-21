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
		void insert(ListNode* head, ListNode* node, int n) {
			ListNode* cur = head;
			for (int i = 1; i < n - 1; i++) {
				if (!cur->next) {
					cur->next = node;
					return;
				} else {
					cur = cur->next;
				}
			}
			node->next = cur->next;
			cur->next = node;
		}

		void reorderList(ListNode* head) {
			if (!head || !head->next || !head->next->next) return ;
			ListNode* slow = head;
			ListNode* fast = head->next;
			int size = 0;
			while (fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
				size += 2;
			}
			if (!fast) size++;
			else size += 2;
			ListNode* cur = slow->next;
			slow->next = NULL;
			int idx = size / 2 + 1;
			while (cur) {
				ListNode* tmp = cur->next;
				insert(head, cur, idx);
				cur = tmp;
				idx--;
			}
		}
};
