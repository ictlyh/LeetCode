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
    long listToLong(ListNode* head) {
        long e = 1;
        long val = 0;
        while (head) {
            val = val + head->val * e;
            e = e * 10;
            head = head->next;
        }
        return val;
    }
    ListNode* longToList(long val) {
        ListNode* head = NULL;
        while (val) {
            ListNode* node = new ListNode(val % 10);
            node->next = head;
            val = val / 10;
        }
        head = head->next;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long val1 = listToLong(l1);
        long val2 = listToLong(l2);
        return longToList(val1 + val2);
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long i = 1;
        long valueA = 0, valueB = 0, shang;
        while(l1 != NULL) {
            valueA += l1->val * i;
            i *= 10;
            l1 = l1->next;
        }
        i = 1;
        while(l2 != NULL) {
            valueB += l2->val * i;
            i *= 10;
            l2 = l2->next;
        }
        shang = valueA + valueB;
        ListNode *ans = new ListNode(shang % 10);
        ListNode *cur = ans;
        shang /= 10;
        while(shang) {
            cur->next = new ListNode(shang % 10);
            cur = cur->next;
            shang /= 10;
        }
        return ans;
    }
};