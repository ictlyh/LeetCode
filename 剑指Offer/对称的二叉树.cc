class Solution {
  public:
    bool isSymmetrical(TreeNode* pRoot)
    {
      if (!pRoot) return true;
      return isMirror(pRoot->left, pRoot->right);
    }
    bool isMirror(TreeNode* left, TreeNode* right) {
      if (!left && !right) return true;
      if (!left || !right || left->val != right->val) return false;
      return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
