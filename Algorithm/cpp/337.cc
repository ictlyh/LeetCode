




// Time Limit Exceeded
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
    int robHelper(TreeNode* node, bool parentRobbed) {
      if (!node) return 0;
      if (parentRobbed) {
        return robHelper(node->left, false) + robHelper(node->right, false);
      } else {
        int rob = node->val + robHelper(node->left, true) + robHelper(node->right, true);
        int unrob = robHelper(node->left, false) + robHelper(node->right, false);
        return max(rob, unrob);
      }
    }

    int rob(TreeNode* root) {
      return robHelper(root, false);
    }
};
