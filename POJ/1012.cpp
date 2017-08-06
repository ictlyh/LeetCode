#include <iostream>
#include <vector>

using namespace std;

/*
 * Time Limit Exceeded
 */

bool isMValid(int k, int m) {
  vector<int> persons(2 * k, 1);
  for(int i = k; i < 2 * k; i++) {
    persons[i] = -1;
  }
  vector<int>::iterator removeIte = persons.begin();
  while(persons.size() > k) {
    for(int i = 0; i < m - 1; i++) {
      removeIte++;
      if(removeIte == persons.end()) {
        removeIte = persons.begin();
      }
    }
    if(*removeIte == 1) {
      return false;
    }
    removeIte = persons.erase(removeIte);
    if(removeIte == persons.end()) {
      removeIte = persons.begin();
    }
  }
  return true;
}

int main() {
  int k;
  while(cin >> k) {
    if(0 == k) break;
    for(int m = k + 1; ; m++) {
      if(isMValid(k, m)) {
        cout << m << endl;
        break;
      }
    }
  }
  return 0;
}