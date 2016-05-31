class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
      int count = 0;
      //until the left identical bits, all the right will 
      // be cancelled by increments from m to n;
      while(m != n) {
        m >>= 1;
        n >>= 1;
        count++;
      }
      return m << count;
    }
};
int rangeBitwiseAnd(int m, int n) {
  //remove the right bit-1 until equal to or less than m;
  while (m < n) n &= n - 1; 
  return n;
}

// Time Limit Exceeded
class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
      if (m == n) return m;
      int res = m;
      for (int i = m + 1; i <= n; i++) {
        res &= i;
        if (res == 0) return 0;
      }
      return res;
    }
};
