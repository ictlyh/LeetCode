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
		ListNode* deleteDuplicates(ListNode* head) {
			if (!head || !head->next) return head;
			map<int, bool> mymap;
			while (head) {
				map<int, bool>::iterator ite = mymap.find(head->val);
				if (ite == mymap.end()) {
					mymap.insert(pair<int, bool>(head->val, false));
				} else {
					ite->second = true;
				}
				head = head->next;
			}
			ListNode* dummy = new ListNode(0);
			ListNode* cur = dummy;
			for (map<int, bool>::iterator ite = mymap.begin(); ite != mymap.end(); ite++) {
				if (!ite->second) {
					ListNode* node = new ListNode(ite->first);
					cur->next = node;
					cur = node;
				}
			}
			return dummy->next;
		}
};

// Solution 2
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
		ListNode* deleteDuplicates(ListNode* head) {
			if (!head || !head->next) return head;
			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			ListNode* cur = dummy;
			ListNode* pre = head->next;
			bool repeated = false;
			while (pre) {
				if (pre->val == head->val) {
					repeated = true;
					pre = pre->next;
				} else {
					if (repeated) {
						cur->next = pre;
						head = pre;
						pre = pre->next;
						repeated = false;
					} else {
						cur = head;
						head = pre;
						pre = pre->next;
						repeated = false;
					}
				}
			}
			if (repeated)
				cur->next = NULL;
			else {
				cur->next = head;
				head->next = NULL;
			}
			return dummy->next;
		}
};
