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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> res;
      if (!root) return res;
      queue<TreeNode*> nodes;
      nodes.push(root);
      nodes.push(NULL);
      while (!nodes.empty()) {
        TreeNode* node = nodes.front();
        nodes.pop();
        if (!node) break;
        res.push_back(node->val);
        while (node) {
          if (node->right) nodes.push(node->right);
          if (node->left) nodes.push(node->left);
          node = nodes.front();
          nodes.pop();
        }
        nodes.push(NULL);
      }
      return res;
    }
};
