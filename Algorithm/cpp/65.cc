class Solution {
  public:
    bool isNumber(string s) {
      if (s.empty()) return false;
      int size = s.size();
      if (size == 1){
        if(s[0] <= '9' && s[0] >= '0') return true;
        else return false;
      }
      int first = s.find_first_not_of(' ');
      if (first == -1) return false;
      int last = s.find_last_not_of(' ');

      int i = first;
      if (s[i] == '+'  || s[i] == '-')
        i++;

      bool e = false;
      bool dot = false;
      for (;i <= last; i++) {
        if (s[i] <= '9' && s[i] >= '0') {
          continue;
        } else if (!e && i > first && i < last && s[i] == 'e') {
          e = true;
          if (i == first + 1) 
            if (s[i - 1] < '0' || s[i - 1] > '9') 
              return false;
          if (s[i + 1] == '+' || s[i + 1] == '-') {
            i++;
            if(i >= last) return false;
          }
        } else if (!dot && !e && s[i] == '.') {
          dot = true;
          if ( (i > first && (s[i - 1] <= '9' && s[i - 1] >= '0')) || (i < last && (s[i + 1] <= '9' && s[i + 1] >= '0'))) {
            continue;
          } else {
            return false;
          }
        } else {
          return false;
        }
      }
      return true;
    }
};
