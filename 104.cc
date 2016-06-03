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
};
