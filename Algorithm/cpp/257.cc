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
    void binaryTreePathsHelper(TreeNode* root, string tmp, vector<string>& res) {
      if (!root) return;
      stringstream ss;
      if (tmp.size() == 0) ss << root->val;
      else ss << tmp << "->" << root->val;
      if (!root->left && !root->right) {
        res.push_back(ss.str());
        return;
      }
      if (root->left) binaryTreePathsHelper(root->left, ss.str(), res);
      if (root->right) binaryTreePathsHelper(root->right, ss.str(), res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> res;
      string tmp("");
      binaryTreePathsHelper(root, tmp, res);
      return res;
    }
};
