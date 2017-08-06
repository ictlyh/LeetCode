#include <iostream>
#include <string>
#include <vector>

using namespace std;

int unsortedNess(string str) {
  int res = 0;
  for(int i = 0; i < str.size() - 1; i++) {
    for(int j = i + 1; j < str.size(); j++) {
      if(str[i] > str[j]) res++;
    }
  }
  return res;
}

bool compare(string str1, string str2) {
  if(unsortedNess(str1) <= unsortedNess(str2)) return true;
  return false;
}

void insertSort(vector<string> &strs) {
  if(strs.size() < 2) return;
  for(int i = 1; i < strs.size(); i++) {
    int j = i - 1;
    for(; j >= 0; j--) {
      if(compare(strs[j], strs[i])) break;
    }
    string tmp = strs[i];
    for(int k = i; k > j + 1; k--)
      strs[k] = strs[k - 1];
    strs[j + 1] = tmp;
  }
}

int main() {
  vector<string> strs;
  int n, m;
  cin >> n >> m;
  string str;
  while(m--) {
    cin >> str;
    strs.push_back(str);
  }
  insertSort(strs);
  for(int i = 0; i < strs.size(); i++)
    cout << strs[i] << endl;
  return 0;
}