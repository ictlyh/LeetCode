class Solution {
	public:
		string convertToTitle(int n) {
			string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string res = "";
			while (n > 0) {
				int mod = (n - 1) % 26;
				n = (n - 1) / 26;
				res = str[mod] + res;
			}
			return res;
		}
};
