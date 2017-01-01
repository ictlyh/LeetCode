class Solution {
  public:
    vector<string> split(string str, char c) {
      vector<string> res;
      int b = 0;
      int e = str.find_first_of(c);
      while (e != -1) {
        res.push_back(str.substr(b, e - b));
        b = e + 1;
        e = str.find_first_of(c, b);
      }
      res.push_back(str.substr(b));
      return res;
    }
    void reverseWords(string &s) {
      vector<string> words = split(s, ' ');
      s.clear();
      for (size_t i = words.size() - 1; i > 0; i--) {
        if (words[i].size() == 0) continue;
        s.append(words[i]).append(" ");
      }
      s.append(words[0]);
      int idx = s.find_last_not_of(' ');
      if (idx != -1) s = s.substr(0, idx + 1);
    }
};
