class Solution {
  public:
    int hIndex(vector<int>& citations) {
      int size = citations.size();
      if (size == 1)
        return citations[0] >= 1 ? 1 : 0;
      int h = 0;
      int l = 0;
      int r = size - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (citations[mid] >= size - mid) {
          if (mid == 0 || citations[mid - 1] < size - mid + 1)
            return size - mid;
          else r = mid  - 1;
        } else {
          if (citations[mid + 1] >= size - mid - 1)
            return size - mid - 1;
          else l = mid + 1;
        }
      }
      return h;
    }
};
