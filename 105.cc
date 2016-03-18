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
    TreeNode* build(vector<int>& preorder, int prebegin, int preend,
        vector<int>& inorder, int inbegin, int inend) {
        TreeNode* root;
        if (preend - prebegin == 0)
            root = NULL;
        else if (preend - prebegin == 1)
            root= new TreeNode(preorder[prebegin]);
        else {
            root = new TreeNode(preorder[prebegin]);
            int preidx = prebegin + 1;
            int inidx = inbegin;
            while (inorder[inidx] != preorder[prebegin]) {
                preidx++;
                inidx++;
            }
            root->left = build(preorder, prebegin + 1, preidx, inorder, inbegin, inidx);
            root->right = build(preorder, preidx, preend, inorder, inidx + 1, inend);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};