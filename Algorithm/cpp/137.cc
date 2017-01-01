class Solution {
  public:
    int singleNumber(vector<int>& nums) {
      int res = 0, times = 3;
      for (int i = 0; i < 32; ++i) {
        int mask = 1 << i, cnt = 0;
        for (int num : nums)
          cnt += bool(num & mask);
        if (cnt % times)
          res |= mask;
      }
      return res;
    }
};
