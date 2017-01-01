class Solution {
  public:
    bool isPowerOfFour(int num) {
      if (num < 1) return false;
      int power = 0;
      while (num) {
        int lastBit = num & 1;
        num = num >> 1;
        if (lastBit && num) return false;
        power++;
      }
      return power % 2;
    }
};
class Solution {
  public:
    bool isPowerOfFour(int num) {
      if (num < 1) return false;
      while (num) {
        if (num == 1) return true;
        if (num % 4) return false;
        num = num / 4;
      }
      return false;
    }
};
