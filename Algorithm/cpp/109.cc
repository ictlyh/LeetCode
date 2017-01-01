/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		int listLength(ListNode *node) {
			int len = 0;
			while(node) {
				len++;
				node = node->next;
			}
			return len;
		}

		TreeNode *createTree(ListNode *node, int left, int right) {
			if (left > right)
				return NULL;
			int mid = (left + right) / 2;
			ListNode *p = node;
			for(int i = left; i < mid; i++)
				p = p->next;
			TreeNode *leftNode = createTree(node, left, mid - 1);
			TreeNode *rightNode = createTree(p->next, mid + 1, right);
			TreeNode *tNode = new TreeNode(p->val);
			tNode->left = leftNode;
			tNode->right = rightNode;
			return tNode;        
		}

		TreeNode *sortedListToBST(ListNode *head) {
			int len = listLength(head);
			return createTree(head, 0, len - 1);
		}
};
