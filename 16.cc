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

// Wrong, why?
class Solution {
public:
    int threeSumClosestHelper(vector<int>& nums, int target, int size, int sum, int start) {
        if (size == 3) return sum;
        else {
            long long dis = INT_MAX;
            for (int i = start; i < nums.size(); i++) {
                size++;
                sum += nums[i];
                int d = threeSumClosestHelper(nums, target, size, sum, i + 1);
                dis = abs((long long)d - target) < abs(dis - target) ? d : dis;
                if (d > target) break;
                size--;
                sum -= nums[i];
            }
            return (int)dis;
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return threeSumClosestHelper(nums, target, 0, 0, 0);
    }
};
