class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size() <= 0)
            return result;
        if(k == 1)
            return nums;
        int curMax = myMax(nums, 0, k - 1);
        result.push_back(curMax);
        for(int i = 0; i < nums.size() - k; i++) {
            if(curMax < nums[i + k]) {
                curMax = nums[i + k];
            }
            else if(curMax == nums[i])
                curMax = myMax(nums, i + 1, i + k);
            result.push_back(curMax);
        }
        return result;
    }
    int myMax(vector<int>nums, int begin, int end) {
        int max = nums[begin];
        for(int i = begin + 1; i <= end; i++) {
            if(nums[i] > max)
                max = nums[i];
        } 
        return max;
    }
};