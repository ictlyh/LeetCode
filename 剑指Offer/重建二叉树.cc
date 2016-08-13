class Solution {
  public:
    struct TreeNode* reConstructBinaryTreeHelper(vector<int>& pre, int pre_begin, int pre_end,
        vector<int>& in, int in_begin, int in_end) {
      if (pre_begin > pre_end || in_begin > in_end ||
          pre_end - pre_begin != in_end - in_begin) return NULL;
      TreeNode* root = new TreeNode(pre[pre_begin]);
      int left_length = 0;
      while (in_begin + left_length <= in_end && in[in_begin + left_length] != pre[pre_begin])
        left_length++;
      if (in_begin + left_length > in_end) return NULL;
      root->left = reConstructBinaryTreeHelper(pre, pre_begin + 1, pre_begin + left_length,
          in, in_begin, in_begin + left_length - 1);
      for (int j = in_begin + left_length; j <= in_end; j++)
        if (in[j] < root->val) return NULL;
      root->right = reConstructBinaryTreeHelper(pre, pre_begin + left_length + 1, pre_end,
          in, in_begin + left_length + 1, in_end);
      return root;
    }
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
      return reConstructBinaryTreeHelper(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
    }
};
