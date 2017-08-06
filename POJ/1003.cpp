#include <iostream>

using namespace std;

int numberOfCards(float length) {
  float sum = 0;
  int number = 1;
  while(sum < length) {
    sum += 1.0/(number + 1);
    number++;
  }
  return number - 1;
}

int main() {
  float length;
  while(cin >> length) {
    if(length == 0.0) break;
    cout << numberOfCards(length) << " card(s)" << endl;
  }
  return 0;
}