class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			if(nums.size() < 3) return 0;
			sort(nums.begin(), nums.end());
			int minOffset = nums[0] + nums[1] + nums[2] - target;
			if(minOffset == 0) return target;
			int i = 0;
			while(i < nums.size() - 2) {
				int j = i + 1, k = nums.size()-1;
				while(j < k) {
					int offset = nums[i] + nums[j] + nums[k] - target;
					if(offset == 0) return target;
					minOffset = abs(offset) < abs(minOffset) ? offset : minOffset;
					if(offset < 0) j++;
					else k--;
				}

				i++;
			}
			return target + minOffset;
		}
};
