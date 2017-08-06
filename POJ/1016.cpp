#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define INVENTORY_COUNT 15

using namespace std;

/*
 * Time Limit Exceeded
 */

bool isInventorySame(const vector<pair<int, int>>& digits1,
  const vector<pair<int, int>>& digits2) {
    if(digits1.size() != digits2.size()) return false;
    for(int i = 0; i < digits1.size(); i++) {
      if(digits1[i].first != digits2[i].first
        || digits1[i].second != digits2[i].second) return false;
    }
    return true;
}

vector<pair<int, int>> buildInventoryFromVector(vector<int>& digits) {
  sort(digits.begin(), digits.end());
  int previousValue = -1;
  int count = 0;
  vector<pair<int, int>> res;
  for(int i = 0; i < digits.size(); i++) {
    if(digits[i] != previousValue) {
      if(count) {
        res.push_back(make_pair(count, previousValue));
        count = 0;
      }
    }
    count++;
    previousValue = digits[i];
  }
  if(count) res.push_back(make_pair(count, previousValue));
  return res;
}

vector<pair<int, int>> getInventory(const vector<pair<int, int>>& digits) {
  vector<int> tmp;
  for(int i = 0; i < digits.size(); i++) {
    tmp.push_back(digits[i].first);
    tmp.push_back(digits[i].second);
  }
  return buildInventoryFromVector(tmp);
}

vector<pair<int, int>> buildInventoryFromString(string str) {
  vector<int> tmp;
  for(int i = 0; i < str.size(); i++) {
    tmp.push_back(str[i] - '0');
  }
  return buildInventoryFromVector(tmp);
}

bool isSelfInventory(const vector<pair<int, int>>& digits) {
  return isInventorySame(digits, getInventory(digits));
}

bool isInventoryAfterSteps(const vector<pair<int, int>>& digits, int& length) {
  vector<pair<int, int>> tmp(digits);
  for(int i = 1; i < INVENTORY_COUNT; i++) {
    tmp = getInventory(tmp);
    if(isSelfInventory(tmp)) {
      length = i + 1;
      return true;
    }
  }
  return false;
}

bool isInventoryLoop(const vector<pair<int, int>>& digits, int& length) {
  vector<pair<int, int>> tmp(digits);
  for(int i = 1; i < INVENTORY_COUNT; i++) {
    tmp = getInventory(tmp);
    if(isInventorySame(digits, tmp)) {
      length = i;
      return true;
    }
  }
  return false;
}

int main() {
  string num;
  while (cin >> num) {
    if(-1 == strtod(num.c_str(), NULL)) break;
    int length = 0;
    vector<pair<int, int>> digits = buildInventoryFromString(num);
    stringstream ss;
    for(int i = 0; i < digits.size(); i++) {
      ss << digits[i].first << digits[i].second;
    }
    if(ss.str() == num) {
      cout << num << " is self-inventorying" << endl;
    } else if(isInventoryAfterSteps(digits, length)) {
      cout << num << " is self-inventorying after " << length << " steps" << endl;
    } else if(isInventoryLoop(digits, length)) {
      cout << num << " enters an inventory loop of length " << length << endl;
    } else {
      cout << num << " can not be classified after 15 iterations" << endl;
    }
  }
  return 0;
}