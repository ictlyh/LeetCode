class Solution {
	public:
		int nthUglyNumber(int n) {
			if (n <= 6) return n;
			vector<int> uglys;
			uglys.push_back(1);
			int exp2 = 0;
			int exp3 = 0;
			int exp5 = 0;
			for (int i = 1; i < n; i++) {
				int ugly = min(uglys[exp2] * 2, min(uglys[exp3] * 3, uglys[exp5] * 5));
				uglys.push_back(ugly);
				if (ugly == uglys[exp2] * 2)
					exp2++;
				if (ugly == uglys[exp3] * 3)
					exp3++;
				if (ugly == uglys[exp5] * 5)
					exp5++;
			}
			return uglys.back();
		}
};
