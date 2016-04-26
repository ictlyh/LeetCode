class Solution {
	public:
		int divide(int dividend, int divisor) {
			long long result = 0;
			long long m = abs((long long)dividend);
			long long n = abs((long long)divisor);
			while (m >= n) {
				long long s = n, power = 1;
				while ((s << 1) <= m) {
					s <<= 1;
					power <<= 1;
				}
				result += power;
				m -= s;
			}
			if ((dividend > 0) ^ (divisor > 0)) result = -result;
			return result > INT_MAX ? INT_MAX : result;
		}
};


// Time Limit Exceeded
class Solution {
	public:
		int divide(int dividend, int divisor) {
			if (divisor == 0) return 0;
			if (dividend == INT_MIN && divisor == -1) return INT_MAX;
			bool negative = dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0;
			long m = abs(dividend);
			long n = abs(divisor);
			long sum = 0;
			long count = 0;
			while (sum < m) {
				count++;
				sum += n;
			}
			if (sum > dividend) count--;
			if (negative) count = -count;
			return count;
		}
};
