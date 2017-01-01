/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  public:
    stack<TreeNode*> parents;
    BSTIterator(TreeNode *root) {
      while (root) {
        parents.push(root);
        root = root->left;
      }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return !parents.empty();
    }

    /** @return the next smallest number */
    int next() {
      TreeNode* ptr = parents.top();
      parents.pop();
      TreeNode* tmp = ptr->right;
      while (tmp) {
        parents.push(tmp);
        tmp = tmp->left;
      }
      return ptr->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
class BSTIterator {
  public:
    stack<TreeNode*> parents;
    TreeNode* ptr;
    BSTIterator(TreeNode *root) {
      ptr = root;
      while (ptr && ptr->left) {
        parents.push(ptr);
        ptr = ptr->left;
      }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return ptr != NULL;
    }

    /** @return the next smallest number */
    int next() {
      int val = ptr->val;
      if (ptr->right) {
        parents.push(ptr);
        ptr = ptr->right;
        while (ptr->left) {
          parents.push(ptr);
          ptr = ptr->left;
        }
      } else {
        TreeNode* parent = NULL;
        while (!parents.empty()) {
          parent = parents.top();
          parents.pop();
          if (ptr == parent->left) break;
          else ptr = parent;
        }
        if (!parent || ptr != parent->left) ptr = NULL;
        else ptr = parent;
      }
      return val;
    }
};
