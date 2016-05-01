class Solution {
  public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      if (n == 1) return 1;
      vector<int> idx(primes.size(), 0);
      vector<int> vals(1, 1);
      for (int i = 1; i < n; i++) {
        int min = vals[idx[0]] * primes[0];
        for (int j = 1; j < primes.size(); j++) {
          int tmp = vals[idx[j]] * primes[j];
          min = min < tmp ? min : tmp;
        }
        vals.push_back(min);
        for (int j = 0; j < primes.size(); j++)
          if (min == vals[idx[j]] * primes[j])
            idx[j]++;
      }
      return vals.back();
    }
};
