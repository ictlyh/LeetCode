class Solution {
  public:
    void restoreIpAddressesHelper(string& s, int dotNum, int idx, string str, string lastVal,
        vector<string>& res) {
      if (dotNum > 3 || idx > s.size() || atoi(lastVal.c_str()) > 255 || lastVal.size() > 3) return;
      if (dotNum == 3 && idx == s.size() && str.back() != '.')
        res.push_back(str);
      if (str.back() == '.') {
        restoreIpAddressesHelper(s, dotNum, idx + 1, str + s[idx], string(1, s[idx]), res);
      } else {
        restoreIpAddressesHelper(s, dotNum + 1, idx, str + '.', string(""), res);
        if (lastVal[0] != '0')
          restoreIpAddressesHelper(s, dotNum, idx + 1, str + s[idx], lastVal + s[idx], res);
      }
    }
    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      if (s.size() < 4) return res;
      restoreIpAddressesHelper(s, 0, 1, string(1, s[0]), string(1, s[0]), res);
      return res;
    }
};
class Solution {
  public:
    bool isValid(string s) {
      if (stoi(s) > 255 || s[0] == '0' && s.size() > 1) return false;
      return true;
    }
    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      for (int i = 1; i < 4; i++)
        for (int j = 1; j < 4; j++)
          for (int k = 1; k < 4; k++)
            for (int m = 1; m < 4; m++)
              if (i + j + k + m == s.size()) {
                string a = s.substr(0, i);
                string b = s.substr(i, j);
                string c = s.substr(i + j, k);
                string d = s.substr(i + j + k, m);
                if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                  stringstream ss;
                  ss << a << "." << b << "." << c << "." << d;
                  res.push_back(ss.str());
                }
              }
      return res;
    }
};
