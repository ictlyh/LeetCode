// 关键是找到不大于 n 的整数中有多少个是平方数
class Solution {
public:
int bulbSwitch(int n) {
    // find how many perfect squares in [1,n]
    int count = 0;
    for(int i=1;i*i<=n;i++)
        count++;
    return count;

}
};

// Time Limit Exceended
class Solution {
  public:
    int bulbSwitch(int n) {
      if (n < 0) return 0;
      vector<bool> res(n + 1, false);
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j * i <= n; j++)
          res[i * j] = res[i * j] ? false : true;
      }
      int count = 0;
      for (int i = 1; i <= n; i++)
        count += res[i] ? 1 : 0;
      return count;
    }
};

// Time Limit Exceended
class Solution {
  public:
    void prime_table(int n, vector<int>& primes) { 
      int i, j, k; 
      primes.push_back(2);
      for (i = 3;i <= n;i += 2) {
        bool isPrime = true;
        for (j = 0; j < primes.size() && primes[j] <= sqrt(i); j++) {
          if (i % primes[j] == 0) {
            isPrime = false;
            break;
          }
        }
        if (isPrime) primes.push_back(i);
      }
    }

    int ApproximateNumber(int n, const vector<int>& primes) { 
      int result = 1, count, i;
      for (i = 0; i < primes.size(); i++) { 
        count = 0; 
        while (n % primes[i] == 0) { 
          count++; 
          n /= primes[i];
        }
        result *= (count + 1); 
      } 
      return result; 
    }

    int bulbSwitch(int n) {
      if (n < 0) return 0;
      int count = 0;
      vector<int> primes;
      prime_table(n, primes);
      for (int i = 1; i <= n; i++)
        if (ApproximateNumber(i, primes) % 2) count++;
      return count;
    }
};
