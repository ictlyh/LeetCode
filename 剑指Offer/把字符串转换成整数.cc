class Solution {
  public:
    int StrToInt(string str) {
      int res = 0;
      bool neg = false;
      int i;
      for (i = 0; i < str.size(); i++) {
        if (i == 0) {
          if (str[i] == '-') neg = true;
          else if (str[i] == '+') neg = false;
          else if (!isdigit(str[i])) return 0;
          else res = str[i] - '0';
        } else {
          if (!isdigit(str[i])) break;
          else res = res * 10 + str[i] - '0';
        }
      }
      if (i != str.size()) return 0;
      else return neg ? -res : res;
    }
};
