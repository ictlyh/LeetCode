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
    void flatten(TreeNode* root) {
      if (!root || !root->left && !root->right) return;
      stack<TreeNode*> nodes;
      nodes.push(root);
      TreeNode* dummy = new TreeNode(0);
      TreeNode* ptr = dummy;
      while (!nodes.empty()) {
        root = nodes.top();
        nodes.pop();
        if (root->right) nodes.push(root->right);
        if (root->left) nodes.push(root->left);
        root->left = NULL;
        root->right = NULL;
        dummy->right = root;
        dummy = root;
      }
      root = dummy->right;
    }
};
