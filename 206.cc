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
		ListNode* reverseList(ListNode* head) {
			if (head == NULL) return NULL;
			stack<ListNode*> mystack;
			while (head) {
				mystack.push(head);
				head = head->next;
			}
			ListNode* res = mystack.top();
			mystack.pop();
			ListNode* cur = res;
			while (mystack.size()) {
				cur->next = mystack.top();
				cur = cur->next;
				mystack.pop();
			}
			cur->next = NULL;
			return res;
		}
};


// Better solution
ListNode* revertList(ListNode* head, ListNode** newHead) {
	if (!head) return head;
	if (head->next) {
		ListNode* tail = revertList(head->next, newHead);
		tail->next = head;
		head->next = NULL;
	}
	else *newHead = head;
	return head;
}

ListNode* reverseList(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* newHead = new ListNode(0);
	revertList(head, &newHead);
	return newHead;
}
