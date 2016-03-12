class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = nums[0];
        for (int i = 0, j = 1; j < nums.size(); j++) {
            int count = 1;
            res = nums[i];
            while (nums[j] == nums[i]) {
                count++;
                j++;
            }
            if (count > nums.size() / 2) return res;
            else i = j;
        }
        return res;
    }
};