class Solution {
	public:
		int mySqrt(int x) {
			if (x < 2) return x;
			int p = 0, q = x;
			while (p < q) {
				q = (p + q) / 2;  
				p = x / q;
			}
			return min(p, q);
		}
};
