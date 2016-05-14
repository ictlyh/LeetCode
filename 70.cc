class Solution {
  public:
    int climbStairs(int n) {
      if (n == 0) return 0;
      if (n == 1) return 1;
      if (n == 2) return 2;
      int res[2] = {1, 2};
      int idx = 1;
      int dir = -1;
      for (int i = 2; i < n; i++) {
        idx += dir;
        res[idx] = res[0] + res[1];
        dir = -dir;
      }
      return res[0] > res[1] ? res[0] : res[1];
    }
};

class Solution {
  public:
    int climbStairs(int n) {
      if (n == 0) return 0;
      if (n == 1) return 1;
      if (n == 2) return 2;
      vector<int> res;
      res.push_back(0);
      res.push_back(1);
      res.push_back(2);
      for (int i = 3; i <= n; i++)
        res.push_back(res[i - 2] + res[i - 1]);
      return res.back();
    }
};

// Time Limit Exceeded
class Solution {
  public:
    int climbStairs(int n) {
      if (n == 0) return 0;
      if (n == 1) return 1;
      if (n == 2) return 2;
      return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
