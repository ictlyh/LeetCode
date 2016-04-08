/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {
			if (head == NULL) return NULL;
			unordered_map<RandomListNode*, int> oldList;
			unordered_map<int, RandomListNode*> newList;
			RandomListNode *newHead = new RandomListNode(head->label);
			oldList[head] = 1;
			newList[1] = newHead;
			RandomListNode *current = head->next;
			RandomListNode *ptr = newHead;
			int i = 2;
			while (current != NULL) {
				ptr->next = new RandomListNode(current->label);
				oldList[current] = i;
				newList[i] = ptr->next;
				i++;
				current = current->next;
				ptr = ptr->next;
			}
			current = head;
			ptr = newHead;
			while (current != NULL) {
				ptr->random = newList[oldList[current->random]];
				current = current->next;
				ptr = ptr->next;
			}
			return newHead;
		}
};
