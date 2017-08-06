#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

/*
 * Time Limit Exceeded: Time complicity row * col
 */

int getNthValue(vector<pair<int, int>>& matrix, int nth) {
  int sum = 0, i = 0;
  while(i < matrix.size() && sum < nth) {
    sum += matrix[i].second;
    i++;
  }
  return matrix[i - 1].first;
}

bool isCoordValid(int row, int col, int r, int c) {
  if (r < 0 || r >= row || c < 0 || c >= col) return false;
  return true;
}

int getMaxAbsValue(int row, int col, vector<pair<int, int>>& matrix, int nth) {
  int left_up = -1, up = -1, right_up = -1, left = -1;
  int right = -1, left_down = -1, down = -1, right_down = -1;

  int nthValue = getNthValue(matrix, nth);
  int r = (nth - 1) / col;
  int c = (nth - 1) % col;

  if(isCoordValid(row, col, r - 1, c - 1))
    left_up = abs(getNthValue(matrix, nth) - getNthValue(matrix, nth - col - 1));

  if(isCoordValid(row, col, r - 1, c))
    up = abs(getNthValue(matrix, nth) - getNthValue(matrix, nth - col));

  if(isCoordValid(row, col, r - 1, c + 1))
    right_up = abs(getNthValue(matrix, nth) - getNthValue(matrix, nth - col + 1));

  if(isCoordValid(row, col, r, c - 1))
    left = abs(getNthValue(matrix, nth) - getNthValue(matrix, nth - 1));

  if(isCoordValid(row, col, r, c + 1))
    right = abs(getNthValue(matrix, nth) - getNthValue(matrix, nth + 1));

  if(isCoordValid(row, col, r + 1, c - 1))
    left_down = abs(getNthValue(matrix, nth) - getNthValue(matrix, nth + col - 1));

  if(isCoordValid(row, col, r + 1, c))
    down = abs(getNthValue(matrix, nth) - getNthValue(matrix, nth + col));

  if(isCoordValid(row, col, r + 1, c + 1))
    right_down = abs(getNthValue(matrix, nth) - getNthValue(matrix, nth + col + 1));

  int res = 0;
  res = res > left_up ? res : left_up;
  res = res > up ? res : up;
  res = res > right_up ? res : right_up;
  res = res > left ? res : left;
  res = res > right ? res : right;
  res = res > left_down ? res : left_down;
  res = res > down ? res : down;
  res = res > right_down ? res : right_down;
  return res;
}

void transform(int row, int col, vector<pair<int, int>>& matrix) {
  int count = row * col;
  vector<pair<int, int>> res;
  int before = -1;
  for(int i = 1; i <= count; i++) {
    int maxAbsValue = getMaxAbsValue(row, col, matrix, i);
    if(maxAbsValue != before) {
      res.push_back(make_pair(maxAbsValue, 1));
      before = maxAbsValue;
    } else {
      res.rbegin()->second++;
    }
  }
  cout << col << endl;
  for(int i = 0; i < res.size(); i++)
    cout << res[i].first << " " << res[i].second << endl;
  cout << "0 0" << endl;
}

int main() {
  int col;
  while(cin >> col) {
    if(col == 0) break;
    int value, num, count = 0;
    vector<pair<int, int>> matrix;
    while(cin >> value >> num){
      if(value == 0 && num == 0) break;
      matrix.push_back(make_pair(value, num));
      count += num;
    }
    transform(count / col, col, matrix);
  }
  cout << "0" << endl;
  return 0;
}