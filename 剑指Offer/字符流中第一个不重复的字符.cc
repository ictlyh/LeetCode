class Solution {
  public:
    //Insert one char from stringstream
    void Insert(char ch) {
      count[ch]++;
      str.push_back(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
      for (char c : str)
        if (count[c] == 1) return c;
      return '#';
    }
  private:
    int count[256] = { 0 };
    vector<char> str;
};
