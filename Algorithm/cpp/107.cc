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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> res;
      if (root == NULL) return res;
      queue<TreeNode*> nodes;
      nodes.push(root);
      nodes.push(NULL);
      while (!nodes.empty()) {
        vector<int> level;
        TreeNode* node = nodes.front();
        nodes.pop();
        if (node == NULL) break;
        while (node != NULL) {
          level.push_back(node->val);
          if (node->left) nodes.push(node->left);
          if (node->right) nodes.push(node->right);
          node = nodes.front();
          nodes.pop();
        }
        res.push_back(level);
        nodes.push(NULL);
      }
      vector<vector<int>> result(res.rbegin(), res.rend());
      return result;
    }
};
