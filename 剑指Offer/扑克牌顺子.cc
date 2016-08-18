class Solution {
  public:
    bool IsContinuous( vector<int> numbers ) {
      sort(numbers.begin(), numbers.end());
      int zerocount = 0;
      for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) {
          zerocount++;
        } else if (i == numbers.size() - 1) {
          return true;
        } else if (numbers[i + 1] == numbers[i]) {
          return false;
        } else if (numbers[i + 1] - numbers[i] > 1) {
          if (numbers[i + 1] - numbers[i] - 1 > zerocount)
            return false;
          else zerocount -= (numbers[i + 1] - numbers[i] - 1);
        }
      }
      return false;
    }
};
