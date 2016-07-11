class Solution {
  public:
    vector<int> diffWaysToCompute(string input) {
      int size_str = input.size();
      vector<int> result;
      for(int i = 0; i < size_str; i++) {
        if(isOperator(input[i])) {
          vector<int> left = diffWaysToCompute(input.substr(0, i));
          vector<int> right = diffWaysToCompute(input.substr(i + 1));
          for(int a : left) {
            for(int b : right) {
              if(input[i] == '+')  result.push_back(a + b);
              if(input[i] == '-')  result.push_back(a - b);
              if(input[i] == '*')  result.push_back(a * b);
            }
          }
        }
      }
      return result.size() > 0 ? result : vector<int>{ stoi(input) };
    }

    bool isOperator(char c) {
      return  c == '+' || c == '-' || c == '*';
    }
};
