class Solution {
	public:
		string addBinary(string a, string b) {
			if (a.size() == 0) return b;
			if (b.size() == 0) return a;
			int i = a.size() - 1;
			int j = b.size() - 1;
			int carry = 0;
			string res;
			for (; i >= 0 && j >= 0; i--, j--) {
				int tmp = a[i] + b[j] + carry - 96;
				res.insert(res.begin(), 48 + tmp % 2);
				carry = tmp > 1 ? 1 : 0;
			}
			while (i >= 0) {
				int tmp = a[i] + carry - 48;
				res.insert(res.begin(), 48 + tmp % 2);
				carry = tmp > 1 ? 1 : 0;
				i--;
			}
			while (j >= 0) {
				int tmp = b[j] + carry - 48;
				res.insert(res.begin(), 48 + tmp % 2);
				carry = tmp > 1 ? 1 : 0;
				j--;
			}
			if (carry) res.insert(res.begin(), '1');
			return res;
		}
};
