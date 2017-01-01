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
    bool maxValInBST(TreeNode* root, int& ma) {
      if (!root) return true;
      while (root->right) {
        root = root->right;
      }
      ma = root->val;
      return false;
    }

    bool minValInBST(TreeNode* root, int& mi) {
      if (!root) return true;
      while (root->left) {
        root = root->left;
      }
      mi = root->val;
      return false;
    }

    bool isValidBST(TreeNode* root) {
      if (!root || !root->left && !root->right) return true;
      bool tmp1 = isValidBST(root->left) && isValidBST(root->right);
      int mi, ma;
      bool tmp2 = minValInBST(root->right, mi) || mi > root->val;
      bool tmp3 = maxValInBST(root->left, ma) || ma < root->val;
      return tmp1 && tmp2 && tmp3;
    }
};
