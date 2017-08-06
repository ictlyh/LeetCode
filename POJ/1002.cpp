#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string transform(string str) {
  string des("");
  for (int i = 0; i < str.size(); i++) {
    if(str[i] >= '0' && str[i] <= '9') {
      des.push_back(str[i]);
    } else {
      switch(str[i]) {
      case 'A':
      case 'B':
      case 'C':
        des.push_back('2');
        break;
      case 'D':
      case 'E':
      case 'F':
        des.push_back('3');
        break;
      case 'G':
      case 'H':
      case 'I':
        des.push_back('4');
        break;
      case 'J':
      case 'K':
      case 'L':
        des.push_back('5');
        break;
      case 'M':
      case 'N':
      case 'O':
        des.push_back('6');
        break;
      case 'P':
      case 'R':
      case 'S':
        des.push_back('7');
        break;
      case 'T':
      case 'U':
      case 'V':
        des.push_back('8');
        break;
      case 'W':
      case 'X':
      case 'Y':
        des.push_back('9');
        break;
      default:
        break;
      }
    }
  }
  des.insert(3, 1, '-');
  return des;
}

int main() {
  int n;
  string s;
  vector<string>strs;
  vector<pair<string, int>> maps;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    strs.push_back(transform(s));
  }
  sort(strs.begin(), strs.end());
  int i = 0;
  while(i < n) {
    int count = 1;
    while(++i < n && strs[i] == strs[i - 1])
      count++;
    if(count > 1) {
      maps.push_back(make_pair(strs[i - 1], count));
    }
  }
  if(maps.size() == 0) {
    cout << "No duplicates. " << endl;
  } else {
    for(int i = 0; i < maps.size(); i++)
      cout << maps[i].first << " " << maps[i].second << endl;
  }
  return 0;
}