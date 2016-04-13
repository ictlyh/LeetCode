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
		bool isPalindrome(ListNode* head) {
			vector<ListNode*> nodes;
			ListNode* ptr = head;
			while (ptr != NULL) {
				nodes.push_back(ptr);
				ptr = ptr->next;
			}
			int left = 0;
			int right = nodes.size() - 1;
			while (left <= right) {
				if (nodes[left]->val != nodes[right]->val) return false;
				left++;
				right--;
			}
			return true;
		}
};
