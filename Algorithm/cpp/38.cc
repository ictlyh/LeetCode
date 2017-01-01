class Solution {
public:
string generateNextStr(string s) {
  if (s.size() == 0) return string("");
  stringstream ss;
  int count = 1;
  char c = s[0];
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == c) count++;
    else {
      ss << count << c;
      count = 1;
      c = s[i];
    }
  }
  ss << count << c;
  return ss.str();
}

string countAndSay(int n) {
  if (n == 0) return "";
  string res("1");
  if (n == 1) return res;
  for (int i = 1; i < n; i++)
    res = generateNextStr(res);
  return res;
}
};
