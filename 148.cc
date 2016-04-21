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
		ListNode* sortList(ListNode* head) {
			if (!head || !head->next) return head;
			vector<int> vals;
			while (head) {
				vals.push_back(head->val);
				head = head->next;
			}
			sort(vals.begin(), vals.end());
			ListNode* dummy = new ListNode(0);
			head = dummy; 
			for (int i = 0; i < vals.size(); i++) {
				head->next = new ListNode(vals[i]);
				head = head->next;
			}
			return dummy->next;
		}
};
