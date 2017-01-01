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
    vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode*> st;
      vector<int> res;
      if (root == NULL) return res;
      while (root != NULL) {
        st.push(root);
        root = root->left;
        while (root == NULL) {
          if (st.empty()) return res;
          root = st.top();
          st.pop();
          res.push_back(root->val);
          root = root->right;
        }
      }
      return res;
    }
};
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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<TreeNode*> stack;
      vector<int> res;
      if (root == NULL) return res;
      while (root != NULL) {
        stack.push_back(root);
        root = root->left;
        while (root == NULL) {
          if (stack.size() == 0) return res;
          root = stack.back();
          stack.pop_back();
          res.push_back(root->val);
          root = root->right;
        }
      }
      return res;
    }
};
