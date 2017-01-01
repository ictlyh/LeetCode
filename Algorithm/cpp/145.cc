class Solution {
public:
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> res;
  if (!root) return res;
  stack<TreeNode*> nodes;
  nodes.push(root);
  TreeNode* node = NULL;
  while (!nodes.empty()) {
    node = nodes.top();
    nodes.pop();
    res.push_back(node->val);
    if (node->left) nodes.push(node->left);
    if (node->right) nodes.push(node->right);
  }
  vector<int> result(res.rbegin(), res.rend());
  return result;
}
};

class Solution {
  public:
    void postorderTraversalHelper(TreeNode* root, vector<int>& res) {
      if (!root) return;
      postorderTraversalHelper(root->left, res);
      postorderTraversalHelper(root->right, res);
      res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> res;
      postorderTraversalHelper(root, res);
      return res;
    }
};
