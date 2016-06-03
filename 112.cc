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
    bool hasPathSumHelper(TreeNode* node, int cur_sum, int sum) {
      if (!node) return false;
      cur_sum += node->val;
      if (!node->left && !node->right)
        return cur_sum == sum;
      //if (cur_sum > sum) return false; // if all node values are non-negative
      return hasPathSumHelper(node->left, cur_sum, sum) ||
        hasPathSumHelper(node->right, cur_sum, sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
      return hasPathSumHelper(root, 0, sum);
    }
};
