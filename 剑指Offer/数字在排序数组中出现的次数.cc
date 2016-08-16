class Solution {
  public:
    int GetNumberOfK(vector<int> data ,int k) {
      int l = leftIndex(data, k);
      if (l == -1) return 0;
      int r = rightIndex(data, k);
      return r - l + 1;
    }
    int leftIndex(vector<int>& data, int k) {
      int l = 0, r = data.size() - 1;
      int idx = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (data[mid] < k) l = mid + 1;
        else if (data[mid] > k) r = mid - 1;
        else if (mid == l || data[mid - 1] != k) {
          idx = mid;
          break;
        } else r = mid - 1;
      }
      return idx;
    }
    int rightIndex(vector<int>& data, int k) {
      int l = 0, r = data.size() - 1;
      int idx = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (data[mid] < k) l = mid + 1;
        else if (data[mid] > k) r = mid - 1;
        else if (mid == r || data[mid + 1] != k) {
          idx = mid;
          break;
        } else l = mid + 1;
      }
      return idx;
    }
};
