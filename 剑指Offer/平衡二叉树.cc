class Solution {
  public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
      int depth;
      return IsBalancedTree(pRoot, depth);
    }
    bool IsBalancedTree(TreeNode* pRoot, int& depth) {
      if (!pRoot) {
        depth = 0;
        return true;
      }
      if (!pRoot->left && !pRoot->right) {
        depth = 1;
        return true;
      }
      int leftDepth, rightDepth;
      bool left = IsBalancedTree(pRoot->left, leftDepth);
      bool right = IsBalancedTree(pRoot->right, rightDepth);
      depth = max(leftDepth, rightDepth) + 1;
      return left && right && abs(leftDepth - rightDepth) <= 1;
    }
};
