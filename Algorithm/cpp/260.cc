class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
      uint32_t xor_result = 0;
      for(int i : nums)
        xor_result ^= (uint32_t)i;

      // find the lowest 1 bit
      uint32_t unique_bit = xor_result & (~xor_result + 1);

      int single1 = 0, single2 = 0;
      for(int i : nums) {
        if(i & unique_bit) single1 ^= i;
        else single2 ^= i;
      }
      vector<int> res;
      res.push_back(single1);
      res.push_back(single2);
      return res;
    }
};
