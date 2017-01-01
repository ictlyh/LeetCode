class Solution {
	public:
		bool isPowerOfThree(int x) {
			if (x < 1) return false;
			while (x) {
				if (x == 1) return true;
				if (x % 3) return false;
				x = x / 3;
			}
			return false;
		}
};
