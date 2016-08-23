class Solution {
  public:
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
      if (!pRoot) return NULL;
      TreeNode* left = KthNode(pRoot->left, k);
      if (left) return left;
      if (++count == k) return pRoot;
      return KthNode(pRoot->right, k);
    }  
};
