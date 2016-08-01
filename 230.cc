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
      return kthSmallestHelper(root, k);
    }
    int kthSmallestHelper(TreeNode* root, int &k) {
      if (root == NULL) return -1;
      int val = kthSmallestHelper(root->left, k);
      if (k == 0) return val;
      else if (--k == 0) return root->val;
      else return kthSmallestHelper(root->right, k);
    }
};
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
