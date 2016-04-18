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
		ListNode *detectCycle(ListNode *head) {
			unordered_map<ListNode*, bool> mymap;
			ListNode* ptr = head;
			while (ptr){
				if (mymap.find(ptr) == mymap.end())
					mymap[ptr] = true;
				else return ptr;
				ptr = ptr->next;
			}
			return NULL;
		}
};
