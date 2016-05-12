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
    int countNodesHelper(TreeNode * root) {
      if (!root) return 0;
      int left_depth = 0, right_depth = 0;
      TreeNode* l = root;
      TreeNode* r = root;
      while (l) { 
        left_depth++; 
        l = l->left; 
      }
      while (r) {
        right_depth++;
        r = r->right; 
      }
      if(right_depth == left_depth) return pow(2, right_depth) - 1;
      return countNodesHelper(root->left) + countNodesHelper(root->right) + 1;
    }
    int countNodes(TreeNode* root) {
      return countNodesHelper(root);
    }
};


// Time Limit Exceeded
class Solution {
  public:
    int countNodes(TreeNode* root) {
      if (root == NULL) return 0;
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
