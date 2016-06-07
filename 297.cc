/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if (!root) return "";
      queue<TreeNode*> nodes;
      nodes.push(root);
      stringstream ss;
      while (!nodes.empty()) {
        root = nodes.front();
        nodes.pop();
        if (root) {
          ss << root->val << ",";
          nodes.push(root->left);
          nodes.push(root->right);
        }
        else ss << "#,"; 
      }
      string str = ss.str();
      while (str.back() == '#' || str.back() == ',')
        str.pop_back();
      str.push_back(',');
      return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      if (data.empty()) return NULL;
      queue<TreeNode*> nodes;
      int i = data.find_first_of(',');
      int rootval = atoi(data.substr(0, i).c_str());
      TreeNode* root = new TreeNode(rootval);
      nodes.push(root);
      i++;
      if (i >= data.size()) return root;
      while (!nodes.empty()) {
        TreeNode* node = nodes.front();
        nodes.pop();
        if (data[i] == '#') i += 2;
        else {
          int j = data.find_first_of(',', i);
          node->left = new TreeNode(atoi(data.substr(i, j - i).c_str()));
          nodes.push(node->left);
          i = j + 1;
        }
        if (i >= data.size()) break;
        if (data[i] == '#') i += 2;
        else {
          int j = data.find_first_of(',', i);
          node->right = new TreeNode(atoi(data.substr(i, j - i).c_str()));
          nodes.push(node->right);
          i = j + 1;
        }
        if (i >= data.size()) break;
      }
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
