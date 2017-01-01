class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int prevMin = nums[0], prevMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int prod1 = prevMin * nums[i];
            int prod2 = prevMax * nums[i];
            prevMin = min(nums[i], min(prod1, prod2));
            prevMax = max(nums[i], max(prod1, prod2));
            res = max(prevMax, res);
        }
        return res;
    }
};