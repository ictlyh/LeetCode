class Solution {
	public:
		int reverse(int x) {
			long val = 0;
			while (x) {
				val = val * 10 + x % 10;
				x /= 10;
			}
			if (val > 0)
				return val > INT_MAX ? 0 : val;
			else return val < INT_MIN ? 0 : val;
		}
};
