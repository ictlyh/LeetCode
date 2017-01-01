class Solution {
	public:
		int jump(vector<int>& nums) {
			int res = 0, start = 0;
			while (start < nums.size() - 1) {
				res++;
				int len = nums[start], maxlen = 0, index = 0;
				if (start + len >= nums.size() - 1)
					return res;
				for (int i = 1; i <= len; i++) {
					if (nums[start + i] + i > maxlen) {
						maxlen = nums[start + i] + i;
						index = start + i;
					}
				}
				start = index;
			}
			return res;
		}
};


// Time Limit Exceeded
class Solution {
	public:
		int minJump(vector<int>& nums, int m, int n) {
			if (m == n) return 0;
			if (nums[m] >= n - m) return 1;
			int mini = n - m;
			for (int i = m + 1; i < n; i++) {
				int step = minJump(nums, m, i) + minJump(nums, i, n);
				mini = step < mini ? step : mini;
			}
			return mini;
		}

		int jump(vector<int>& nums) {
			return minJump(nums, 0, nums.size() - 1);
		}
};
