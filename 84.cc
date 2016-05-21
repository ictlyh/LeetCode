class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
      int res = 0;
      for (int i = 0; i < heights.size(); ++i) {
        // find the local max (greater than left and right)
        if (i + 1 < heights.size() && heights[i] <= heights[i + 1]) continue;
        int minh = heights[i];
        for (int j = i; j >= 0; --j) {
          minh = min(minh, heights[j]);
          res = max(res, minh * (i - j + 1));
        }
      }
      return res;
    }
};
