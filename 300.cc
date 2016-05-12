class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
      int size = nums.size(), max = 0;
      if (size < 2) return size;
      vector<int> dist(size, 1);
      for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++ ) {
          if (nums[j] < nums[i] && dist[i] < dist[j] + 1)
            dist[i] = dist[j] + 1;
        }
        if (dist[i] > max) max = dist[i];
      }
      return max;
    }
};
