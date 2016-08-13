class Solution {
  public:
    void reOrderArray(vector<int> &array) {
      vector<int> evens;
      vector<int>::iterator ite = array.begin();
      while (ite != array.end()) {
        if (*ite % 2 == 0) {
          evens.push_back(*ite);
          ite = array.erase(ite);
        } else ite++;
      }
      array.insert(array.begin() + array.size(), evens.begin(), evens.end());
    }
};
