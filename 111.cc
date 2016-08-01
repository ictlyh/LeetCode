class Solution {
public:
int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<TreeNode*> que;
    que.push(root);
    int i = 0;
    while (!que.empty()) {
        i++;
        int k = que.size();
        for (int j = 0; j < k; j++) {
            TreeNode* rt = que.front();
            if (rt->left) que.push(rt->left);
            if (rt->right) que.push(rt->right);
            que.pop();
            if (rt->left == NULL && rt->right == NULL) return i;
        }
    }
    return -1; //For the compiler thing. The code never runs here.
}
};
class Solution {
  public:
    int minDepth(TreeNode* root) {
      if (root == NULL) return 0;
      else if (root->left == NULL) return 1 + minDepth(root->right);
      else if (root->right == NULL) return 1 + minDepth(root->left);
      else return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
class Solution {
  public:
    void minDepthHelper(TreeNode* node, int cur_depth, int& min_depth) {
      if (!node) return;
      cur_depth++;
      if (cur_depth >= min_depth) return;
      if (!node->left && !node->right) {
        min_depth = cur_depth;
        return;
      }
      minDepthHelper(node->left, cur_depth, min_depth);
      minDepthHelper(node->right, cur_depth, min_depth);
    }

    int minDepth(TreeNode* root) {
      if (!root) return 0;
      if (!root->left && !root->right) return 1;
      int min_depth = INT_MAX;
      minDepthHelper(root, 0, min_depth);
      return min_depth;
    }
};
