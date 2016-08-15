class Solution {
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
      if (input.size() < k) return vector<int>();
      sort(input.begin(), input.end());
      return vector<int>(input.begin(), input.begin() + k);
    }
};

// 超时，为什么？
class Solution {
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
      if (input.size() <= k) return input;
      int left = 0, right = input.size() - 1;
      while (true) {
        int l = left, r = right;
        int pivot = input[l];
        while (l < r) {
          int pivot = input[l];
          while (l < r && input[r] >= pivot) r--;
          if (l < r) input[l++] = input[r];
          while (l < r && input[l] <= pivot) l++;
          if (l < r) input[r--] = input[l];
        }
        input[l] = pivot;
        if (l == k) {
          return vector<int>(input.begin(), input.begin() + k);
        } else if (l < k) {
          left = l;
        } else {
          right = l;
        }
      }
    }
};
