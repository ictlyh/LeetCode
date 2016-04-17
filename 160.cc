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
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (!headA || !headB) return NULL;
			unordered_map<ListNode*, bool> mymap;
			ListNode* cur = headA;
			while (cur) {
				if (mymap.find(cur) == mymap.end())
					mymap[cur] = true;
				cur = cur->next;
			}
			cur = headB;
			while (cur) {
				if (mymap.find(cur) != mymap.end()) return cur;
				cur = cur->next;
			}
			return NULL;
		}
};
