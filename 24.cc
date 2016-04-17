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
		ListNode* swapPairs(ListNode* head) {
			vector<ListNode*> nodes;
			ListNode* cur = head;
			while (cur) {
				nodes.push_back(cur);
				cur = cur->next;
			}
			if (nodes.size() < 2) return head;
			bool even = nodes.size() % 2 == 0;
			head = nodes.at(1);
			head->next = nodes.at(0);
			cur = nodes.at(0);
			int end = even ? nodes.size() : nodes.size() - 1;
			for (int i = 2; i < end; i += 2) {
				cur->next = nodes.at(i + 1);
				cur->next->next = nodes.at(i);
				cur = nodes.at(i);
			}
			if (even) cur->next = NULL;
			else cur->next = nodes.back();
			return head;
		}
};
