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
    void recursion(TreeNode *root, int level, vector<int> &res) {
      if (root == NULL) return ;
      if (res.size() < level) res.push_back(root->val);
      recursion(root->right, level + 1, res);
      recursion(root->left, level + 1, res);
    }
    vector<int> rightSideView(TreeNode *root) {
      vector<int> res;
      recursion(root, 1, res);
      return res;
    }
};
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
