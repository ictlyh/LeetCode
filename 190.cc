class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
      queue<int> bits;
      for (int i = 0; i < 32; i++) {
        bits.push(n & 0x0001);
        n >>= 1;
      }
      uint32_t res = 0;
      while (!bits.empty()) {
        res <<= 1;
        res += bits.front();
        bits.pop();
      }
      return res;
    }
};
