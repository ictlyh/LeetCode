class Solution {
  public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
      TreeNode *head = NULL, *tail = NULL;
      ConvertHelper(pRootOfTree, &head, &tail);
      return head;
    }
    void ConvertHelper(TreeNode* node, TreeNode** head, TreeNode** tail) {
      if (!node) {
        *head = NULL;
        *tail = NULL;
      } else if (!node->left && !node->right) {
        *head = node;
        *tail = node;
      } else {
        TreeNode *lhead = NULL, *ltail = NULL;
        TreeNode *rhead = NULL, *rtail = NULL;
        ConvertHelper(node->left, &lhead, &ltail);
        ConvertHelper(node->right, &rhead, &rtail);
        if (node->left) {
          node->left = ltail;
          ltail->right = node;
        }
        if (node->right) {
          node->right = rhead;
          rhead->left = node;
        }
        if (lhead) *head = lhead;
        else *head = node;
        if (rtail) *tail = rtail;
        else *tail = node;
      }
    }
};
