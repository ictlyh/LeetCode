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
};

class WordDictionary {
  private:
    TrieNode* root;
  public:
    WordDictionary() {
      root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
      TrieNode* ptr = root;
      for (int i = 0; i < word.size(); i++) {
        if (ptr->child[word[i] - 'a'] == NULL) {
          ptr->child[word[i] - 'a'] = new TrieNode();
          ptr->child[word[i] - 'a']->label = word[i] - 'a';
        }
        ptr = ptr->child[word[i] - 'a'];
      }
      ptr->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
      return searchBFS(root, word, 0);
    }
    bool searchBFS(TrieNode* ptr, string& word, int idx) {
      for (int i = idx; i < word.size(); i++) {
        if (word[i] == '.') {
          for (TrieNode* child : ptr->child)
            if (child && searchBFS(child, word, i + 1))
              return true;
          return false;
        } else if (ptr->child[word[i] - 'a'] == NULL)
          return false;
        else ptr = ptr->child[word[i] - 'a'];
      }
      return ptr->isEnd;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
