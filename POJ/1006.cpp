#include <iostream>

#define MAX_TRIPLE_PEAK 21252
#define PPERIOD 23
#define EPERIOD 28
#define IPERIOD 33

using namespace std;

/*
 * Wrong Answer
 * 没有错误 case...
 */
int nextPeak(int p, int e, int i, int d) {
  int maxdate = (p > e) ? (p > i ? p : i) : (e > i ? e : i);
  int begin = d >= maxdate ? d : maxdate - 1;
  for(int offset = 1; offset <= MAX_TRIPLE_PEAK; offset++) {
    int date = begin + offset;
    int poffset = date - p;
    int eoffset = date - e;
    int ioffset = date - i;
    if(poffset % PPERIOD ==0 && eoffset % EPERIOD == 0 && ioffset % IPERIOD == 0)
      return begin + offset - d;
  }
  return -1;
}

int main() {
  int p, e, i, d;
  int n = 1;
  while(cin >> p >> e >> i >> d) {
    if(p == e && e == i && i == d && d == -1) break;
    cout << "Case " << n <<": the next triple peak occurs in "
      << nextPeak(p, e, i, d) << " days." << endl;
    n++;
  }
  return 0;
}