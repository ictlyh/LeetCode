class Solution {
  public:
    int GetUglyNumber_Solution(int index) {
      if (index == 0) return 0;
      vector<int> uglys(index, 1);
      int idx2 = 0, idx3 = 0, idx5 = 0;
      for (int i = 1; i < index; i++) {
        uglys[i] = min(2 * uglys[idx2], min(3 * uglys[idx3], 5 * uglys[idx5]));
        if (uglys[i] == 2 * uglys[idx2]) idx2++;
        if (uglys[i] == 3 * uglys[idx3]) idx3++;
        if (uglys[i] == 5 * uglys[idx5]) idx5++;
      }
      return uglys[index - 1];
    }
};
