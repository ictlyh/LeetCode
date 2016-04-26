class Solution {
	public:
		void reverse(vector<int>& nums, int begin, int end) {
			for(int i = begin; i < (begin + end + 1) / 2; i++)
				std::swap(nums[i], nums[end + begin - i]);
		}
		void nextPermutation(vector<int>& nums) {
			int size = nums.size();
			int i = size - 1, j = size - 1;
			while(i > 0 && nums[i] <= nums[i-1]) i--;
			if(i == 0) {
				reverse(nums, 0, size - 1);
				return ;
			}
			while(nums[j] <= nums[i - 1]) j--;
			std::swap(nums[j], nums[i - 1]);
			reverse(nums, i, size - 1);
		}
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> res;
			int count = 1;
			for (int i = 2; i <= nums.size(); i++)
				count *= i;
			for (int i = 0; i < count; i++) {
				res.push_back(nums);
				nextPermutation(nums);
			}
			return res;
		}
};
