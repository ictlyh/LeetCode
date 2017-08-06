#include <iostream>

using namespace std;

#define NUMBER_OF_MONTH 12

int main() {
  double sum = 0.0;
  double balance;
  for(int i = 0; i < NUMBER_OF_MONTH; i++) {
    cin >> balance;
    sum += balance;
  }
  cout << "$" << sum / NUMBER_OF_MONTH;
  return 0;
}