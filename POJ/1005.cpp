#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_YEAY 30
#define PI 3.141592653

int main() {
  vector<double> radius;
  for(int i = 1; i <= MAX_YEAY; i++) {
    radius.push_back(sqrt(100.0 * i / PI));
  }
  int n;
  double x, y;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x >> y;
    for(int j = 0; j < MAX_YEAY; j++) {
      if(sqrt(pow(x, 2) + pow(y, 2)) < radius[j]) {
        cout << "Property " << i + 1 << ": This property will begin eroding in year "
          << j + 1 << "." << endl;
        break;
      }
    }
  }
  cout << "END OF OUTPUT." << endl;
  return 0;
}