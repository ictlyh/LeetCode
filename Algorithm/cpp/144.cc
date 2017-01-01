class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      if (root == NULL) return res;
      stack<TreeNode*> nodes;
      TreeNode* node = NULL;
      nodes.push(root);
      while (!nodes.empty()) {
        node = nodes.top();
        nodes.pop();
        res.push_back(node->val);
        if (node->right) nodes.push(node->right);
        if (node->left) nodes.push(node->left);
      }
      return res;
    }
};
