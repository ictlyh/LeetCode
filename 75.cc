class Solution {
	public:
		void sortColors(vector<int>& nums) {
			int count[] = { 0, 0, 0 };
			int i = 0;
			for (; i < nums.size(); i++)
				count[nums[i]]++;
			for (i = 0; i < count[0]; i++)
				nums[i] = 0;
			for (; i < count[0] + count[1]; i++)
				nums[i] = 1;
			for (; i < nums.size(); i++)
				nums[i] = 2;

		}
};
