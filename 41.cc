class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			vector<bool> exist(nums.size(), false);
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] > 0 && nums[i] <= nums.size())
					exist[nums[i] - 1] = true;
			}
			for (int i = 0; i < nums.size(); i++)
				if (!exist[i]) return i + 1;
			return nums.size() + 1;
		}
};
