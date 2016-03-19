class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], highest = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum = sum < 0 ? nums[i] : sum + nums[i];
            highest = max(highest, sum);
        }
        return highest;
    }
};