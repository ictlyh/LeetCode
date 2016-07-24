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
    bool isBalancedHelper(TreeNode* node, int& height) {
      if (node == NULL) {
        height = 0;
        return true;
      }
      bool lbal, rbal;
      int lhei, rhei;
      lbal = isBalancedHelper(node->left, lhei);
      rbal = isBalancedHelper(node->right, rhei);
      height = max(lhei, rhei) + 1;
      return lbal && rbal && abs(lhei - rhei) <= 1;
    }
    bool isBalanced(TreeNode* root) {
      int height;
      return isBalancedHelper(root, height);
    }
};
class Solution {
  public:
    void maxDepthHelper(TreeNode* node, int cur_depth, int& max_depth) {
      if (!node) return;
      cur_depth++;
      if (!node->left && !node->right) {
        max_depth = max_depth < cur_depth ? cur_depth : max_depth;
        return;
      }
      maxDepthHelper(node->left, cur_depth, max_depth);
      maxDepthHelper(node->right, cur_depth, max_depth);
    }

    int maxDepth(TreeNode* root) {
      if (!root) return 0;
      if (!root->left && !root->right) return 1;
      int max_depth = 0;
      maxDepthHelper(root, 0, max_depth);
      return max_depth;
    }

    bool isBalancedHelper(TreeNode* left, TreeNode* right) {
      if (!left && !right) return true;
      if (!left) return !right->left && !right->right;
      if (!right) return !left->left && !left->right;
      if (abs(maxDepth(left) - maxDepth(right)) > 1) return false;
      return isBalancedHelper(left->left, left->right) &&
        isBalancedHelper(right->left, right->right);
    }
    bool isBalanced(TreeNode* root) {
      if (!root) return true;
      return isBalancedHelper(root->left, root->right);
    }
};
