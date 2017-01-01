class Solution {
	public:
		bool isPalindrome(int x) {
			if(x < 0) return false;
			if(x < 10) return true;
			if(x % 10 == 0) return false;
			int r = 0;
			int xx = x;
			while (xx) {
				r = r * 10 + xx % 10;
				xx = xx / 10;
			}
			if (r == x) return true;
			return false;
		}
};
