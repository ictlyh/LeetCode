class Solution {
  public:
    int rectCover(int number) {
      if (number < 3) return number;
      int a[] = { 1, 2 };
      for (int i = 2; i < number; i++)
        a[i % 2] = a[0] + a[1];
      return max(a[0], a[1]);
    }
};
