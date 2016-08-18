class Solution {
  public:
    void reverse(string& str) {
      int b = 0, e = str.size() - 1;
      while (b < e) {
        swap(str[b++], str[e--]);
      }
    }
    string ReverseSentence(string str) {
      stringstream ssi(str);
      stringstream sso;
      string res, word;
      bool isfirst = true;
      while (getline(ssi, word, ' ')) {
        reverse(word);
        if (isfirst) {
          isfirst = false;
          sso << word;
        } else sso << " " << word;
      }
      res = sso.str();
      reverse(res);
      return res;
    }
};
