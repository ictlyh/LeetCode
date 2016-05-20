class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if (root == NULL) return res;
      queue<TreeNode*> nodes;
      nodes.push(root);
      nodes.push(NULL);
      bool leftToRight = true;
      while (nodes.size() > 1) {
        vector<int> tmp;
        TreeNode* node = nodes.front();
        nodes.pop();
        while (node) {
          if (leftToRight)  tmp.push_back(node->val);
          else tmp.insert(tmp.begin(), node->val);
          if (node->left) nodes.push(node->left);
          if (node->right) nodes.push(node->right);
          node = nodes.front();
          nodes.pop();
        }
        res.push_back(tmp);
        leftToRight = !leftToRight;
        nodes.push(NULL);
      }
      return res;
    }
};
