class TrieNode {
  public:
    int label;
    bool isEnd;
    vector<TrieNode*> child;
    // Initialize your data structure here.
    TrieNode() {
      label = -1;
      isEnd = false;
      child.clear();
      child = vector<TrieNode*>(26, NULL);
    }
    TrieNode(int c) {
      label = c;
      isEnd = false;
      child.clear();
      child = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
  private:
    TrieNode* root;
  public:
    Trie() {
      root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
      TrieNode* ptr = root;
      for (int i = 0; i < word.size(); i++) {
        if (ptr->child[word[i] - 'a'] == NULL)
          ptr->child[word[i] - 'a'] = new TrieNode(word[i] - 'a');
        ptr = ptr->child[word[i] - 'a'];
      }
      ptr->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
      TrieNode* ptr = root;
      for (int i = 0; i < word.size(); i++) {
        if (ptr->child[word[i] - 'a'] == NULL)
          return false;
        ptr = ptr->child[word[i] - 'a'];
      }
      return ptr->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
      TrieNode* ptr = root;
      for (int i = 0; i < prefix.size(); i++) {
        if (ptr->child[prefix[i] - 'a'] == NULL)
          return false;
        ptr = ptr->child[prefix[i] - 'a'];
      }
      return true;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
