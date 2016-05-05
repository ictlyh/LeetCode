string generateNextStr(string s) {
  if (s.size() == 0) return string("");
  string res;
  for (int i = 0; i < s.size(); i++) {
    int count = 1;
    while(i < s.size() - 1 && s[i] == s[i + 1]) {
      count++;
      i++;
    }
    res.append(1, (char)(count + '0'));
    res.append(1, s[i]);
  }
  return res;
}

string countAndSayHelper(int n) {
  if (n < 2) return string("1");
  string s = countAndSayHelper(n - 1);
  return generateNextStr(s);
}

string countAndSay(int n) {
  return countAndSayHelper(n);
}
