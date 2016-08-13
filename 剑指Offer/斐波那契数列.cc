class Solution {
  public:
    int Fibonacci(int n) {
      if (n <= 0) return 0;
      if (n == 1) return 1;
      int a[] = { 0, 1 };
      for (int i = 2; i <= n; i++) {
        a[i % 2] = a[0] + a[1];
      }
      return max(a[0], a[1]);
    }
};
