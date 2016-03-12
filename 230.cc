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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        bool flag = false;
        return midOrderTraverse(root, k, count, flag);
    }
    int midOrderTraverse(TreeNode* node, int k, int &count, bool &flag) {
        if(node == NULL) {
            flag = false;
            return 0;
        }
        int tmp = midOrderTraverse(node->left, k, count, flag);
        if(flag)
            return tmp;
        count++;
        if(count == k) {
            flag = true;
            return node->val;
        }
        tmp = midOrderTraverse(node->right, k, count, flag);
        if(flag)
            return tmp;
    }
};