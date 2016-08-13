class Solution {
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
      queue<TreeNode*> nodes;
      vector<int> res;
      if (!root) return res;
      nodes.push(root);
      while (!nodes.empty()) {
        TreeNode* node = nodes.front();
        nodes.pop();
        res.push_back(node->val);
        if (node->left) nodes.push(node->left);
        if (node->right) nodes.push(node->right);
      }
      return res;
    }
};
