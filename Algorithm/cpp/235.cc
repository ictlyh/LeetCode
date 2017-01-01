class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* pointer = root;
        while (pointer) {
            if ((pointer->val - p->val) * (pointer->val - q->val) <= 0) return pointer;
            else if (pointer->val > p->val && pointer->val > q->val) pointer = pointer->left;
            else pointer = pointer->right;
        }
        return pointer;
    }
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> pPath, qPath;
        TreeNode *pointer = root;
        while(pointer->val != p->val) {
            if(pointer->val > p->val) {
                pPath.push_back(0);
                pointer = pointer->left;
            }
            else {
                pPath.push_back(1);
                pointer = pointer->right;
            }
        }
        pointer = root;
        while(pointer->val != q->val) {
            if(pointer->val > q->val) {
                qPath.push_back(0);
                pointer = pointer->left;
            }
            else {
                qPath.push_back(1);
                pointer = pointer->right;
            }
        }
        pointer = root;
        for(int i = 0; i < pPath.size() && i < qPath.size(); i++) {
            if(pPath[i] != qPath[i])
                return pointer;
            else {
                if(pPath[i] == 0)
                    pointer = pointer->left;
                else pointer = pointer->right;
            }
        }
        return pointer;
    }
};
class Solution {
public:
    bool isAncestor(TreeNode* root, TreeNode* v) {
        if(root == NULL)
            return false;
        if(root->val == v->val)
            return true;
        else return (isAncestor(root->left, v) || isAncestor(root->right, v));
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(isAncestor(root->left, p) && isAncestor(root->left, q))
            return lowestCommonAncestor(root->left, p, q);
        else if(isAncestor(root->right, p) && isAncestor(root->right, q))
            return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};
