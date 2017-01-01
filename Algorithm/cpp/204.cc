class Solution {
	public:
		int countPrimes(int n) {
			if ( n <= 2) return 0;
			int count = 0;
			vector<bool> isPrime(n, true);
			for (int i = 2; i < n; i++) {
				if (isPrime[i]){
					count++;
					for (int j = 2; i * j < n; j++)
						isPrime[i * j] = false;
				}
			}
			return count;
		}
};
