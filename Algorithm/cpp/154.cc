class Solution {
	public:
		int findMin(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			return nums[0];
		}
};

class Solution {
	public:
		int findMin(vector<int>& nums) {
			int left = 0;
			int right = nums.size() - 1;
			int middle;
			while(left < right)
			{
				middle = (left + right) / 2;
				if(nums[middle] > nums[right])
					left = middle + 1;
				else if(nums[middle] < nums[right])
					right = middle;
				else
					right--;
			}

			return nums[left];
		}
};
