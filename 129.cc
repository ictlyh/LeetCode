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
    void sumNumbersHelper(TreeNode* node, string tmp, vector<string>& res) {
      if (!node) return;
      stringstream ss;
      ss << tmp << node->val;
      if (!node->left && !node->right) {
        res.push_back(ss.str());
        return;
      }
      if (node->left) sumNumbersHelper(node->left, ss.str(), res);
      if (node->right) sumNumbersHelper(node->right, ss.str(), res);
    }

    int sumNumbers(TreeNode* root) {
      vector<string> res;
      sumNumbersHelper(root, "", res);
      int sum = 0;
      for (string str : res)
        sum += atoi(str.c_str());
      return sum;
    }
};
