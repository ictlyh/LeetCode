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
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* ptr = dummy;
    while (head) {
        if (head->val == val) {
            ptr->next = head->next;
        } else ptr = head;
        head = head->next;
    }
    return dummy->next;
}
};
