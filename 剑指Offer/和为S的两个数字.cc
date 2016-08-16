class Solution {
  public:
    static bool comparator(const vector<int>& nums1, const vector<int>& nums2) {
      return nums1[0] * nums1[1] < nums2[0] * nums2[1];
    }
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
      vector<vector<int>> res;
      int l = 0, r = array.size() - 1;
      while (l < r) {
        if (array[l] + array[r] == sum) {
          vector<int> tmp;
          tmp.push_back(array[l]);
          tmp.push_back(array[r]);
          res.push_back(tmp);
          l++;
        } else if (array[l] + array[r] < sum) {
          l++;
        } else r--;
      }
      sort(res.begin(), res.end(), comparator);
      if (res.size() == 0) return vector<int>();
      else return res.front();
    }
};
