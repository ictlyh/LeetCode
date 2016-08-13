class Solution {
  public:
    void Mirror(TreeNode *pRoot) {
      if (!pRoot) return;
      Mirror(pRoot->left);
      Mirror(pRoot->right);
      TreeNode* tmpr = pRoot->right;
      pRoot->right = pRoot->left;
      pRoot->left = tmpr;   
    }
};
