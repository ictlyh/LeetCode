class Solution {
	public:
		bool isPowerOfTwo(int num) {
			if (num < 1) return false;
			int count = 0;
			while (num) {
				count++;
				num &= (num - 1);
			}
			return count == 1;
		}
};


class Solution {
	public:
		bool isPowerOfTwo(int n) {
			return n == 0 ? false : (n == 1 ? true : (n % 2 == 1 ? false : isPowerOfTwo(n / 2)));
		}
};
