#include <iostream>
#include <string>
#include <vector>

using namespace std;

string turnIntoInt(const char* value, int& digits) {
  string res(value);
  int point = res.find('.');
  if(point != string::npos) {
    while(res[res.size() - 1] == '0') res.erase(res.size() - 1, 1);
    digits = res.size() - point - 1;
    res.erase(point, 1);
  } else {
    digits = 0;
    while(res[0] == '0') res.erase(res.begin());
  }
  return res;
}


string multiply(const char* v1, const char* v2) {
  int v1digit, v2digit;
  string s1 = turnIntoInt(v1, v1digit);
  string s2 = turnIntoInt(v2, v2digit);
  int v1len = s1.size();
  int v2len = s2.size();
  int totalLen = v1len + v2len;
  vector<string> muls;
  for(int i = v2len - 1; i >= 0; i--) {
    int carry = 0;
    string mul(totalLen, '0');
    for(int j = v1len - 1; j >= 0; j--) {
      int sum = (s2[i] - '0') * (s1[j] - '0') + carry;
      mul[i + j + 1] = sum % 10 + '0';
      carry = sum / 10;
    }
    if(carry != 0) mul[i] = carry + '0';
    muls.push_back(mul);
  }
  int carry = 0;
  string res(totalLen, '0');
  for(int i = totalLen - 1; i >= 0; i--) {
    int sum = carry;
    for(int j = 0; j < v2len; j++) {
      sum += muls[j][i] - '0';
    }
    res[i] = sum % 10 + '0';
    carry = sum / 10;
  }
  if(v1digit + v2digit != 0)
    res.insert(totalLen - (v1digit + v2digit), 1, '.');
  while(res[0] == '0') res.erase(res.begin());
  return res;
}

int main() {
  string r;
  int n;
  while(cin >> r >> n) {
    if(strtod(r.c_str(), NULL) == 0) {
      cout << "0" << endl;
    } else if(n == 0) {
      cout << "1" << endl;
    } else {
      string res("1");
      for(int i = 0; i < n; i++) {
        res = multiply(res.c_str(), r.c_str());
      }
      cout << res.c_str() << endl;
    }
  }
  return 0;
}