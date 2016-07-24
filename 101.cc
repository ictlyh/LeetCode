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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
      if (!left && ! right) return true;
      if (!left || !right || left->val != right->val) return false;
      return isSymmetricHelper(left->left, right->right) &&
        isSymmetricHelper(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
      if (root == NULL) return true;
      return isSymmetricHelper(root->left, root->right);
    }
};

// 或者先构造一个镜像树，再判断两棵树是否相同
