class Solution {
  public:
    int countDigitOne(int n) {
      if (n <= 0) return 0;
      long long int total = 0;
      int high = n, low = 0, cur = 0;
      int number = 1, k = 1;
      while (high > 0) {
        cur = high % 10;
        high /= 10;
        if (cur == 0)
          total += high * number;
        else if (cur == 1)
          total += (high * number + (low + 1));
        else
          total += (high + 1) * number;
        number *= 10;
        low += cur * k;
        k *= 10;
      }
      return total;
    }
};

// Time Limit Exceeded
class Solution {
  public:
    int occurs(int n) {
      int shang = n;
      int yushu;
      int count = 0;
      while(shang != 0) {
        yushu = shang % 10;
        shang = shang / 10;
        if(yushu == 1)
          count ++;
      }
      return count;
    }
    int countDigitOne(int n) {
      int count = 0;
      for(int i = 1; i <= n ; i++)
        count += occurs(i);
      return count;
    }
};
