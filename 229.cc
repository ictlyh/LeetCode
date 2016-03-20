class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        int len = nums.size() / 3;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i + len < nums.size() && nums[i] == nums[i + len]) {
                res.push_back(nums[i]);
                int j = i + len + 1;
                while (j < nums.size() && nums[j] == nums[j - 1]) j++;
                i = j - 1;
            } else {
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
            }
        }
        return res;
    }
};