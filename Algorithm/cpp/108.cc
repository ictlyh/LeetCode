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

    TreeNode* createBST(vector<int>& vals, int left, int right) {
      if (left > right)
        return NULL;
      int mid = (left + right) / 2;
      TreeNode *leftNode = createBST(vals, left, mid - 1);
      TreeNode *rightNode = createBST(vals, mid + 1, right);
      TreeNode *tNode = new TreeNode(vals[mid]);
      tNode->left = leftNode;
      tNode->right = rightNode;
      return tNode;        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return createBST(nums, 0 , nums.size() - 1);
    }
};
