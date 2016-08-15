class Solution {
  public:
    static bool compare(int a, int b) {
      stringstream sa, sb;
      sa << a << b;
      sb << b << a;
      return sa.str() < sb.str();
    }
    string PrintMinNumber(vector<int> numbers) {
      sort(numbers.begin(), numbers.end(), compare);
      stringstream ss;
      for (int number : numbers) {
        ss << number;
      }
      return ss.str();
    }
};
