#include <iostream>
#include <vector>

using namespace std;

#define MAX_MARBLE_VALUE 6

/*
 * Time Limit Exceeded
 */

int getNthMarbleValue(const vector<int>& marbles, int nth) {
  int count = 0;
  for(int i = 0; i < MAX_MARBLE_VALUE; i++) {
    count += marbles[i];
    if(count >= nth) return i + 1;
  }
  return 0;
}

bool sumToValue(const vector<int>& marbles, int marblesCount ,int n, int value) {
  for(int i = 1; i <= marblesCount; i++) {
    if(n & (1 << (i - 1))) value -= getNthMarbleValue(marbles, i);
  }
  return 0 == value; 
}

bool isDivisable(const vector<int>& marbles) {
  int marbelsCount = 0;
  int marbelsValue = 0;
  for(int i = 0; i < MAX_MARBLE_VALUE; i++) {
    marbelsCount += marbles[i];
    marbelsValue += marbles[i] * (i + 1);
  }
  if(marbelsValue % 2) return false;
  marbelsValue /= 2;
  for(int i = 0; i < 1 << marbelsCount; i++) {
    if(sumToValue(marbles, marbelsCount, i, marbelsValue)) return true;
  }
  return false;
}

int main() {
  vector<int> marbles(MAX_MARBLE_VALUE, 0);
  int connection = 0;
  while(true) {
    bool allZero = true;
    for(int i = 0; i < MAX_MARBLE_VALUE; i++) {
      cin >> marbles[i];
      if(0 != marbles[i]) allZero = false;
    }
    if(allZero) break;
    cout << "Collection #" << ++connection << ":\n" 
      << (isDivisable(marbles) ? "Can" : "Can't") << " be divided." << endl;
  }
  return 0;
}