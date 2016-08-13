class Solution {
  public:
    int minNumberInRotateArray(vector<int> rotateArray) {
      int size = rotateArray.size();
      if (0 == size) return 0;
      int l = 0, r = size - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (rotateArray[mid] > rotateArray[mid + 1])
          return rotateArray[mid + 1];
        else if (rotateArray[mid] < rotateArray[l])
          r = mid;
        else l = mid;
      }
      return rotateArray[l];
    }
};
