class Solution {
	public:
		bool isUgly(int num) {
			if (num <= 0) return false;
			bool flag = false;
			while (num != 1) {
				flag = false;
				if (num % 2 == 0) {
					num /= 2;
					flag = true;
				}
				if (num % 3 == 0) {
					num /= 3;
					flag = true;
				}
				if (num % 5 == 0) {
					num /= 5;
					flag = true;
				}
				if (!flag) break;
			}
			return num == 1;
		}
};
