class Solution {
  public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
      vector<vector<int>> res;
      vector<int> curPath;
      FindPathDFS(root, curPath, expectNumber, res);
      return res;
    }
    void FindPathDFS(TreeNode* root, vector<int> curPath, int target, 
        vector<vector<int>>& res) {
      if (!root) return;
      curPath.push_back(root->val);
      target -= root->val;
      if (!root->left && !root->right && !target)
        res.push_back(curPath);
      if (root->left) FindPathDFS(root->left, curPath, target, res);
      if (root->right) FindPathDFS(root->right, curPath, target, res);
    }
};
