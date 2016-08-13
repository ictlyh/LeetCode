class Solution {
  public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
      stack<int> values;
      int size = pushV.size();
      if (size != popV.size()) return false;
      int i = 0, j = 0;
      while (i < size && j < size) {
        while (i < size && (values.empty() || values.top() != popV[j])) {
          values.push(pushV[i++]);
        }
        if (i == size && values.top() != popV[j]) return false;
        while (j < size && !values.empty() && (values.top() == popV[j])) {
          values.pop();
          j++;
        }
      }
      return values.empty();
    }
};
