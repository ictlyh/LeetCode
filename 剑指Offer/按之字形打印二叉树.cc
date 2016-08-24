class Solution {
  public:
    vector<vector<int> > Print(TreeNode* pRoot) {
      bool rever = false;
      queue<TreeNode*> nodes;
      vector<vector<int>> res;
      if (!pRoot) return res;
      nodes.push(pRoot);
      nodes.push(NULL);
      while (!nodes.empty() && nodes.front() != NULL) {
        vector<int> tmp;
        while (nodes.front() != NULL) {
          TreeNode* node = nodes.front();
          nodes.pop();
          tmp.push_back(node->val);
          if (node->left) nodes.push(node->left);
          if (node->right) nodes.push(node->right);
        }
        nodes.pop();
        nodes.push(NULL);
        if (tmp.size() > 0) {
          if (rever) {
            res.push_back(vector<int>(tmp.rbegin(), tmp.rend()));
            rever = false;
          } else {
            res.push_back(tmp);
            rever = true;
          }
        }
      }
      return res;
    }
};
