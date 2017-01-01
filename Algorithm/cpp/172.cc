class Solution {
  public:
    int trailingZeroes(int n) {
      int count = 0;
      for (long long i = 5; n >= i; i *= 5)
        count += n / i;
      return count;
    }
};
class Solution {
  public:
    int trailingZeroes(int n) {
      int count = 0;
      while (n >= 5) {
        count += n / 5;
        n = n / 5;
      }
      return count;
    }
};
