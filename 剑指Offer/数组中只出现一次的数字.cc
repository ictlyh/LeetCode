class Solution {
  public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
      int x_or = 0;
      for (int d : data)
        x_or ^= d;
      x_or &= ~(x_or - 1);
      *num1 = 0, *num2 = 0;
      for (int d : data) {
        if (x_or & d) *num1 ^= d;
        else *num2 ^= d;
      }
    }
};
