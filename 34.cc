class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.front() > target || nums.back() < target ||
        std::find(nums.begin(), nums.end(), target) == nums.end()) {
            vector<int> res(2,-1);
            return res;
        }
        vector<int> res;
        vector<int>::iterator low = std::lower_bound(nums.begin(), nums.end(), target);
        res.push_back(low - nums.begin());
        vector<int>::iterator up = std::upper_bound(nums.begin(), nums.end(), target);
        res.push_back(up - nums.begin() - 1);
        return res;
    }
};