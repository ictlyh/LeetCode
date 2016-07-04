class Solution {
  public:
    int countNumbersWithUniqueDigits(int n) {
      if (n == 0) return 1;
      if (n == 1) return 10;
      if (n == 2) return 91;
      int base = 81, count = 91;
      for (int i = 3; i <= min(10, n); i++) {
        base *= (11 - i);
        count += base;
      }
      return count;
    }
};
