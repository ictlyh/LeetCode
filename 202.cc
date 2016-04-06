class Solution {
	public:
		bool isHappy(int n) {
			int num=0;
			unordered_map<int, bool> table;
			table[n] = true;
			while(n != 1) {
				while(n) {
					num += (n % 10) * (n % 10);
					n /= 10;
				}
				if(table[num]) break;
				else table[num] = true;
				n = num;
				num = 0;
			}
			return 1 == n;
		}
};
