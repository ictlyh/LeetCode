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
    TreeNode* build(vector<int>& inorder, int inbegin, int inend,
        vector<int>& postorder, int postbegin, int postend) {
            TreeNode* root;
        if (inend - inbegin == 0)
            root = NULL;
        else if (inend - inbegin == 1)
            root= new TreeNode(inorder[inbegin]);
        else {
            root = new TreeNode(postorder[--postend]);
            int inidx = inbegin;
            int postidx = postbegin;
            while (inorder[inidx] != postorder[postend]) {
                inidx++;
                postidx++;
            }
            root->left = build(inorder, inbegin, inidx, postorder, postbegin, postidx);
            root->right = build(inorder, inidx + 1, inend, postorder, postidx, postend);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};

// Memory Limit Exceeded
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        if (inorder.size() == 0)
            root = NULL;
        else if (inorder.size() == 1)
            root= new TreeNode(inorder.front());
        else {
            vector<int>::iterator postend = postorder.end();
            postend--;
            TreeNode* root = new TreeNode(*postend);
            vector<int>::iterator inite = inorder.begin();
            vector<int>::iterator postite = postorder.begin();
            while (*inite != *postend) {
                inite++;
                postite++;
            }
            vector<int> lchildInorder(inorder.begin(), inite);
            vector<int> rchildInorder(++inite, inorder.end());
            vector<int> lchildPostorder(postorder.begin(), postite);
            vector<int> rchildPostorder(postite, postend);
            root->left = buildTree(lchildInorder, lchildPostorder);
            root->right = buildTree(rchildInorder, rchildPostorder);
        }
        return root;
    }
};