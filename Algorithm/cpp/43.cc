https://discuss.leetcode.com/topic/30508/easiest-java-solution-with-graph-explanation/2
class Solution {
  public:
    string multiply(string num1, string num2) {
      int m = num1.size();
      int n = num2.size();
      string res(m + n, '0');
      for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
          int mul = (num1[i] - '0') * (num2[j] - '0'); 
          int p1 = i + j, p2 = i + j + 1;
          int sum = mul + res[p2] - '0';
          res[p1] += sum / 10;
          res[p2] = sum % 10 + '0';
        }
      }
      int i = res.find_first_not_of('0');
      if (i == -1) return "0";
      else return res.substr(i);
    }
};
class Solution {
  public:
    string multiply(string num1, string num2) {
      vector<string> res;
      for (int i = num2.size() - 1; i >= 0; i--) {
        string s;
        for(int k = i; k < num2.size() - 1; k++)
          s.insert(s.begin(), '0');
        int carry = 0;
        for (int j = num1.size() - 1; j >= 0; j--) {
          int val = (num2[i] - '0') * (num1[j] - '0') + carry;
          s.insert(s.begin(), val % 10 + '0');
          carry = val / 10;
        }
        if (carry > 0) s.insert(s.begin(), carry + '0');
        res.push_back(s);
      }
      int len = res.back().size();
      for (int i = 0; i < res.size() - 1; i++) {
        for (int j = res[i].size(); j < len; j++)
          res[i].insert(res[i].begin(), '0');
      }
      int carry = 0;
      string result;
      for (int i = len - 1; i >= 0; i--) {
        int val = carry;
        for (int j = 0; j < res.size(); j++)
          val += (res[j][i] - '0');
        result.insert(result.begin(), val % 10 + '0');
        carry = val / 10;
      }
      if (carry > 0) result.insert(result.begin(), carry + '0');
      int i = result.find_first_not_of('0');
      if (i == -1) return "0";
      return result.substr(i);
    }
};
