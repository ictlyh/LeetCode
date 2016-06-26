class Solution {
  public:
    bool isHappy(int n) {
      int num=0;
      unordered_map<int, bool> table;
      table[n] = true;
      while(n != 1) {
        while(n) {
          num += (n % 10) * (n % 10);
          n /= 10;
        }
        if(table[num]) break;
        else table[num] = true;
        n = num;
        num = 0;
      }
      return 1 == n;
    }
};

bool isHappy(int n) {
  int res;
  while (1)
  {
    res = 0;
    for (; n; n/=10) res += (n % 10)*(n % 10);
    n = res;
    if (n == 1) return true;  // n will always come to 1 or 4 ^-^
    else if (n == 4) return false;
  }
}
