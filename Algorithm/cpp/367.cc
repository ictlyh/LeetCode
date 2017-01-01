class Solution {
  public:
    bool isPerfectSquare(int num) {
      if (num < 0) return false;
      int left = 0;
      int right = 46340;
      while (left <= right) {
        int mid = left + right >> 1;
        int temp = mid * mid;
        if (temp == num) return true;
        else if (temp >num) right = mid - 1;
        else left = mid + 1;
      }
      return false;
    }
};
