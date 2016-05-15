class Solution {
  public:
    int countBitsOne(int num) {
      int count = 0;
      while (num) {
        count++;
        num &= (num - 1);
      }
      return count;
    }

    vector<int> countBits(int num) {
      vector<int> res;
      for (int i = 0; i <= num; i++)
        res.push_back(countBitsOne(i));
      return res;
    }
};
