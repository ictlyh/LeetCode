/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
  public:
    void connect(TreeLinkNode* root) {
      if (!root) return;
      queue<TreeLinkNode*> nodes;
      nodes.push(root);
      nodes.push(NULL);
      while (!nodes.empty()) {
        TreeLinkNode* node = nodes.front();
        nodes.pop();
        if (!node) break;
        TreeLinkNode* right = NULL;
        while (node) {
          node->next = right;
          right = node;
          if (node->right) nodes.push(node->right);
          if (node->left) nodes.push(node->left);
          node = nodes.front();
          nodes.pop();
        }
        nodes.push(NULL);
      }
    }
};
