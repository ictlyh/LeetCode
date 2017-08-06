#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Wrong Answer, WHY?
 * POJ 就不能给出出错的 case 来吗？心碎。
 */

typedef struct Wighting{
  string left;
  string right;
  string weight;
};

void counterfeitCoin(const vector<Wighting>& wightings) {
  int idx = -1;
  bool isLight;
  char c = '\0';
  vector<int> result(12, 0);
  for(int i = 0; i < 3; i++) {
    if(wightings[i].weight == string("even")) {
      for(int j = 0; j < wightings[i].left.size(); j++) {
        result[wightings[i].left[j] - 'A']++;
        result[wightings[i].right[j] - 'A']++;
      }
    } else {
      idx = i;
    }
  }
  /* 假设假硬币在左边 */
  for(int i = 0; i < wightings[idx].left.size(); i++) {
    result[wightings[idx].right[i] - 'A']++;
  }
  int candidateCount = 0;
  for(int i = 0; i < wightings[idx].left.size(); i++) {
    if(0 == result[wightings[idx].left[i] - 'A']) {
      c = wightings[idx].left[i];
      candidateCount++;
      if(wightings[idx].weight == string("up")) {
        isLight = false;
      } else {
        isLight = true;
      }
    }
  }
  /* 如果候选结果集不唯一，说明假币在右边 */
  if(candidateCount != 1) {
    /* 左边的出库，右边的入库 */
    for(int i = 0; i < wightings[idx].left.size(); i++) {
      result[wightings[idx].right[i] - 'A']--;
      result[wightings[idx].left[i] - 'A']++;
    }
    for(int i = 0; i < wightings[idx].left.size(); i++) {
      if(0 == result[wightings[idx].right[i] - 'A']) {
        c = wightings[idx].right[i];
        if(wightings[idx].weight == string("up")) {
          isLight = true;
        } else {
          isLight = false;
        }
        break;
      }
    }
  } 
  cout << c << " is the counterfeit coin and it is " 
    << (isLight ? "light." : "heavy.") << endl;
}

int main() {
  int n;
  vector<Wighting> wightings(3);
  cin >> n;
  while(n--) {
    for(int i = 0; i < 3; i++) {
      cin >> wightings[i].left >> wightings[i].right >> wightings[i].weight;
    }
   counterfeitCoin(wightings);
  }
  return 0;
}