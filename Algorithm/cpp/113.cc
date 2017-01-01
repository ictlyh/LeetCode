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
    void pathSumHelper(TreeNode* node, int needed, vector<int> vals, vector<vector<int>>& res) {
      if (!node) return;
      vals.push_back(node->val);
      needed -= node->val;
      if (!node->left && !node->right) {
        if (needed == 0)
          res.push_back(vals);
        return;
      }
      if (node->left) pathSumHelper(node->left, needed, vals, res);
      if (node->right) pathSumHelper(node->right, needed, vals, res);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int>> res;
      vector<int> vals;
      pathSumHelper(root, sum, vals, res);
      return res;
    }
};
