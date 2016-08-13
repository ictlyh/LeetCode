class Solution {
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
      int count = 0, target = 0;
      for (int number : numbers) {
        if (count == 0) {
          target = number;
          count++;
        } else if (number == target) {
          count++;
        } else count--;
      }
      count = 0;
      for (int number : numbers) {
        if (number == target) count++;
      }
      if (count >= (numbers.size() >> 1)) return target;
      else return 0;
    }
};
