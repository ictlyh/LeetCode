class Solution {
  public:
    int Add(int num1, int num2){
      while (num2) {
        int x_or = num1 ^ num2;
        num2 = (num1 & num2) << 1;
        num1 = x_or;
      }
      return num1;
    }
};
